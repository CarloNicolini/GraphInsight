/*
*
*  Copyright (C) 2010 MeVis Medical Solutions AG All Rights Reserved.
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  Further, this software is distributed without any warranty that it is
*  free of the rightful claim of any third person regarding infringement
*  or the like.  Any license provided herein, whether implied or
*  otherwise, applies only to this software file.  Patent licenses, if
*  any, provided herein do not apply to combinations of this program with
*  other software, or any other product whatsoever.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*  Contact information: MeVis Medical Solutions AG, Universitaetsallee 29,
*  28359 Bremen, Germany or:
*
*  http://www.mevis.de
*
*/

//----------------------------------------------------------------------------------
/*!
// \file    PythonQtScriptingConsole.cpp
// \author  Florian Link
// \author  Last changed by $Author: florian $
// \date    2006-10
*/
//----------------------------------------------------------------------------------


#include <fstream>
#include <QMenu>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QApplication>
#include <QTextDocumentFragment>
#include <QTextBlock>
#include <QTextCursor>
#include <QDebug>
#include <QCompleter>
#include <QStringListModel>
#include <QScrollBar>
#include <QTimer>
#include "PythonQtScriptingConsole.h"

//-----------------------------------------------------------------------------
PythonQtScriptingConsole::PythonQtScriptingConsole(QWidget* parent, const PythonQtObjectPtr& context, Qt::WindowFlags windowFlags)
    : QTextEdit(parent)
{
    setWindowFlags(windowFlags);
    this->setCursorWidth(6);
    _defaultTextCharacterFormat = currentCharFormat();
    _context                    = context;
    _historyPosition            = 0;
    _hadError                   = false;

    _completer = new QCompleter(this);
    _completer->setWidget(this);
    QObject::connect(_completer, SIGNAL(activated(const QString&)),
                     this, SLOT(insertCompletion(const QString&)));

    connect(PythonQt::self(), SIGNAL(pythonStdOut(const QString&)), this, SLOT(stdOut(const QString&)));
    connect(PythonQt::self(), SIGNAL(pythonStdErr(const QString&)), this, SLOT(stdErr(const QString&)));

    connect(this,SIGNAL(commandExecuted()),this,SLOT(moveCursorToEndLine()));
    searchMode=false;
    //appendCommandPrompt(false);
}

//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::stdOut(const QString& s)
{
    _stdOut += s;
    int idx;
    while ((idx = _stdOut.indexOf('\n'))!=-1) {
        consoleMessage(_stdOut.left(idx));
        std::cout << _stdOut.left(idx).toLatin1().data() << std::endl;
        _stdOut = _stdOut.mid(idx+1);
    }
}

void PythonQtScriptingConsole::stdErr(const QString& s)
{
    _hadError = true;
    _stdErr += s;
    int idx;
    while ((idx = _stdErr.indexOf('\n'))!=-1) {
        consoleMessage(_stdErr.left(idx));
        std::cerr << _stdErr.left(idx).toLatin1().data() << std::endl;
        _stdErr = _stdErr.mid(idx+1);
    }
}

void PythonQtScriptingConsole::flushStdOut()
{
    if (!_stdOut.isEmpty()) {
        stdOut("\n");
    }
    if (!_stdErr.isEmpty()) {
        stdErr("\n");
    }
}

//-----------------------------------------------------------------------------

PythonQtScriptingConsole::~PythonQtScriptingConsole()
{
}

//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::executeLine(bool storeOnly)
{
    QTextCursor textCursor = this->textCursor();
    textCursor.movePosition(QTextCursor::End);

    // Select the text from the command prompt until the end of the block
    // and get the selected text.
    textCursor.setPosition(commandPromptPosition());
    textCursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    QString code = textCursor.selectedText();

    // this is needed to be more similar to classical console
    if ( !(code.startsWith("\t") || code.startsWith(" ")) && code.isEmpty() && _currentMultiLineCode.isEmpty() )
    {
        this->appendCommandPrompt(false);
        return;
    }

    // i don't know where this trailing space is coming from, blast it!
    if (code.endsWith(" "))
    {
        code.truncate(code.length()-1);
    }

    // Update the history
    _history << code;
    _historyPosition = _history.count();
    _currentMultiLineCode += code + "\n";

    if (!storeOnly)
    {
        executeCode(_currentMultiLineCode);
        _currentMultiLineCode = "";
    }

    // Insert a new command prompt
    appendCommandPrompt(storeOnly);
    emit commandExecuted();
}

void PythonQtScriptingConsole::executeCode(const QString& code)
{
    // put visible cursor to the end of the line
    QTextCursor cursor = QTextEdit::textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);

    // evaluate the code
    _stdOut = "";
    _stdErr = "";
    // A smart pointer that stores a PyObject pointer and that handles reference counting automatically
    PythonQtObjectPtr p;
    PyObject* dict = NULL;
    if (PyModule_Check(_context))
    {
        dict = PyModule_GetDict(_context);
    }
    else if (PyDict_Check(_context))
    {
        dict = _context;
    }
    // Evaluate single statement with Py_single_input http://stackoverflow.com/questions/6149807/python-c-api-why-doesnt-pyrun-string-evaluate-simple-conditional-expressions
    // otherwise if the text has more lines, evaluate it as sequence of statements, returning None
    if (dict)
    {
        if ( code.count("\n")>1 )  //multiline code
            p.setNewRef(PyRun_String(code.toLatin1().data(), Py_file_input, PyModule_GetDict(_context), PyModule_GetDict(_context)));
        else //immediate mode
            p.setNewRef(PyRun_String(code.toLatin1().data(), Py_single_input, dict, dict));
    }

    if (!p)
    {
        PythonQt::self()->handleError();
    }

    flushStdOut();
}

//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::appendCommandPrompt(bool storeOnly)
{
    if (storeOnly)
    {
        _commandPrompt = ". . .  ";
    }
    else
    {
        _commandPrompt = ">>>";
    }
    append(_commandPrompt);

    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
    this->repaint();
}

void PythonQtScriptingConsole::appendWelcomeMessage(const QString &prefixMessage)
{
    this->setPlainText(prefixMessage);
    this->executeCode("import sys");
    // this->executeCode("print \"" +prefixMessage +"\"");
    this->executeCode("pversion= \"Python \" + sys.version ");
    this->executeCode("print pversion.replace(\"\\n\",\" \")");

    this->appendCommandPrompt(false);
}


//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::setCurrentFont(const QColor& color, bool bold) {

    QTextCharFormat charFormat(_defaultTextCharacterFormat);

    QFont font(charFormat.font());
    font.setBold(bold);
    charFormat.setFont(font);

    QBrush brush(charFormat.foreground());
    brush.setColor(color);
    charFormat.setForeground(brush);

    setCurrentCharFormat(charFormat);
}



//-----------------------------------------------------------------------------

int PythonQtScriptingConsole::commandPromptPosition() {

    QTextCursor textCursor(this->textCursor());
    textCursor.movePosition(QTextCursor::End);

    return textCursor.block().position() + _commandPrompt.length();
}



//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::insertCompletion(const QString& completion)
{
    QTextCursor tc = textCursor();
    tc.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
    if (tc.selectedText()==".") {
        tc.insertText(QString(".") + completion);
    } else {
        tc = textCursor();
        tc.movePosition(QTextCursor::StartOfWord, QTextCursor::MoveAnchor);
        tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
        tc.insertText(completion);
        setTextCursor(tc);
    }
}

//-----------------------------------------------------------------------------
void PythonQtScriptingConsole::handleTabCompletion()
{
    QTextCursor textCursor   = this->textCursor();
    int pos = textCursor.position();
    textCursor.setPosition(commandPromptPosition());
    textCursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    int startPos = textCursor.selectionStart();

    int offset = pos-startPos;
    QString text = textCursor.selectedText();
    QString textToComplete;
    int cur = offset;
    //qDebug() << cur ;
    if (cur<0)
    {
        int currentPos=textCursor.position();
        qDebug() << currentPos << " " << commandPromptPosition() ;
        textCursor.setPosition(commandPromptPosition());
        return;
    }
    while (cur--)
    {
        QChar c = text.at(cur);
        if (c.isLetterOrNumber() || c == '.' || c == '_') {
            textToComplete.prepend(c);
        } else {
            break;
        }
    }

    QString lookup;
    QString compareText = textToComplete;
    int dot = compareText.lastIndexOf('.');
    if (dot!=-1) {
        lookup = compareText.mid(0, dot);
        compareText = compareText.mid(dot+1, offset);
    }
    if (!lookup.isEmpty() || !compareText.isEmpty())
    {
        compareText = compareText.toLower();
        QStringList found;
        QStringList l = PythonQt::self()->introspection(_context, lookup, PythonQt::Anything );
        foreach (QString n, l)
        {
            if (n.toLower().startsWith(compareText))
            {
                if (!n.startsWith("__") && !(invisibleCompletitionMethods.contains(n)) )    //xxx carlo, elimina i metodi indesiderati
                    found << n;
            }
        }

        if (!found.isEmpty())
        {
            _completer->setCompletionPrefix(compareText);
            _completer->setCompletionMode(QCompleter::PopupCompletion);
            _completer->setModel(new QStringListModel(found, _completer));
            _completer->setCaseSensitivity(Qt::CaseInsensitive);
            QTextCursor c = this->textCursor();
            c.movePosition(QTextCursor::StartOfWord);
            QRect cr = cursorRect(c);
            cr.setWidth(_completer->popup()->sizeHintForColumn(0)
                        + _completer->popup()->verticalScrollBar()->sizeHint().width());
            cr.translate(0,8);
            _completer->complete(cr);
        }
        else
        {
            _completer->popup()->hide();
        }
    }
    else
    {
        _completer->popup()->hide();
    }
}

void PythonQtScriptingConsole::keyPressEvent(QKeyEvent* event)
{
    if (_completer && _completer->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
        switch (event->key()) {
        case Qt::Key_Return:
            if (!_completer->popup()->currentIndex().isValid()) {
                insertCompletion(_completer->currentCompletion());
                _completer->popup()->hide();
                event->accept();
            }
            event->ignore();
            return;
            break;
        case Qt::Key_Enter:
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:

            event->ignore();
            return; // let the completer do default behavior
        default:
            break;
        }
    }

    // Separately handle CTRL+L otherwise a mess appears when writing before the command prompt
#ifndef __APPLE__ // On linux and windows use the ctrl key
    if (event->modifiers().testFlag(Qt::ControlModifier) && event->key()==Qt::Key_L )
#else // on  use the CTRL key rather than Command key
    if (event->modifiers().testFlag(Qt::MetaModifier) && event->key()==Qt::Key_L)
#endif
    {
        QTextCursor textCursor = this->textCursor();
        textCursor.setPosition(commandPromptPosition());
        textCursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        QString code = textCursor.selectedText();
        // Clear the text
        QTextEdit::clear();
        this->appendCommandPrompt(false);
        this->insertPlainText(code);
    }
#ifdef __APPLE__ //enable copy with CMD+C (ControlModifier is CMD on apple)
    if (event->modifiers().testFlag(Qt::ControlModifier) && event->key()==Qt::Key_C )
    {
        QTextEdit::keyPressEvent(event);
    }
    // newline with shift+ctrl+c (meta modifier on Apple is the ctrl key
    if (event->modifiers().testFlag(Qt::MetaModifier) && event->key()==Qt::Key_C )
    {
        if (event->modifiers().testFlag(Qt::ShiftModifier))
        {
            this->appendCommandPrompt(0);
            moveCursorToEndLine();
        }
    }
#else
    // on Linux and Windows SHIFT+CTRL+C is the text copy otherwise is the interrupt
    if (event->modifiers().testFlag(Qt::ControlModifier) && event->key()==Qt::Key_C )
    {
        if (event->modifiers().testFlag(Qt::ShiftModifier))
        {
            this->appendCommandPrompt(0);
            moveCursorToEndLine();
        }
        else
        QTextEdit::keyPressEvent(event);
    }
#endif

    bool        eventHandled = false;
    QTextCursor textCursor   = this->textCursor();
    int key = event->key();
    switch (key)
    {
    case Qt::Key_Left:
    {
        if (textCursor.position() <= commandPromptPosition()) {

            //QApplication::beep();
            eventHandled = true;
        }
        break;
    }

    case Qt::Key_Up:
    {
        // Display the previous command in the history
        if (_historyPosition>0) {
            _historyPosition--;
            changeHistory();
        }
        eventHandled = true;
        this->moveCursorToEndLine();
        break;
    }

    case Qt::Key_Down:
    {
        // Display the next command in the history
        if (_historyPosition+1<_history.count())
        {
            _historyPosition++;
            changeHistory();
        }
        this->moveCursorToEndLine();
        eventHandled = true;
        break;
    }
    case Qt::Key_R:
    {
#ifndef __APPLE__ // On linux and windows use the ctrl key
        if (event->modifiers().testFlag(Qt::ControlModifier))
#else // on  use the CTRL key rather than Command key
        if (event->modifiers().testFlag(Qt::MetaModifier))
#endif
        {
            if(!searchMode)
                searchMode=true;
        }
        break;
    }
    case Qt::Key_Return:
    {
        QTextCursor textCursor = this->textCursor();
        textCursor.movePosition(QTextCursor::End);

        // Select the text from the command prompt until the end of the block
        // and get the selected text.
        textCursor.setPosition(commandPromptPosition());
        textCursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        QString code = textCursor.selectedText();

        if (!code.isEmpty())
        {
            if ( code.trimmed().endsWith(":") || code.startsWith(" ") || code.startsWith("\t") )
                executeLine(true);
            else
                executeLine(false);
        }
        else
        {
            executeLine(false);
            //appendCommandPrompt(0);
            moveCursorToEndLine();
        }

        eventHandled = true;
        flushStdOut();
        break;
    }
        // Is the backspace key
    case Qt::Key_Backspace:
    {
        if (textCursor.hasSelection())
        {
            cut();
            eventHandled = true;
        }
        else
        {
            // Intercept backspace key event to check if
            // deleting a character is allowed. It is not
            // allowed, if the user wants to delete the
            // command prompt.
            if (textCursor.position() <= commandPromptPosition())
            {
                //QApplication::beep();
                eventHandled = true;
            }
        }
        break;
    }
        // Is the CANC key
    case Qt::Key_Delete:
    {
        cut();
        eventHandled = true;
        break;
    }
        // This is activated on the default key
    default:
    {
        if (key >= Qt::Key_Space && key <= Qt::Key_division) {
            if (textCursor.hasSelection() && !verifySelectionBeforeDeletion()) {
                // The selection must not be deleted.
                eventHandled = true;
            } else {
                // The key is an input character, check if the cursor is
                // behind the last command prompt, else inserting the
                // character is not allowed.
                int commandPromptPosition = this->commandPromptPosition();
                if (textCursor.position() < commandPromptPosition) {
                    textCursor.setPosition(commandPromptPosition);
                    setTextCursor(textCursor);
                }
            }
        }
    }
    }

    if (eventHandled)
    {
        _completer->popup()->hide();
        event->accept();

    }
    else
    {
        QTextEdit::keyPressEvent(event);
        QString text = event->text();
        if (!text.isEmpty()) {
            handleTabCompletion();
        } else {
            _completer->popup()->hide();
        }
        eventHandled = true;
    }
}

//-----------------------------------------------------------------------------
/*
 *void PythonQtScriptingConsole::mousePressEvent(QMouseEvent *e)
{
    QTextEdit::mousePressEvent(e);
    moveCursorToEndLine();
}
*/
//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::cut()
{
    bool deletionAllowed = verifySelectionBeforeDeletion();
    if (deletionAllowed) {
        QTextEdit::cut();
    }
}

//-----------------------------------------------------------------------------

bool PythonQtScriptingConsole::verifySelectionBeforeDeletion() {

    bool deletionAllowed = true;
    QTextCursor textCursor = this->textCursor();
    int commandPromptPosition = this->commandPromptPosition();
    int selectionStart        = textCursor.selectionStart();
    int selectionEnd          = textCursor.selectionEnd();

    if (textCursor.hasSelection())
    {
        // Selected text may only be deleted after the last command prompt.
        // If the selection is partly after the command prompt set the selection
        // to the part and deletion is allowed. If the selection occurs before the
        // last command prompt, then deletion is not allowed.
        if (selectionStart < commandPromptPosition ||
                selectionEnd < commandPromptPosition) {
            // Assure selectionEnd is bigger than selection start
            if (selectionStart > selectionEnd) {
                int tmp         = selectionEnd;
                selectionEnd    = selectionStart;
                selectionStart  = tmp;
            }
            if (selectionEnd < commandPromptPosition) {

                // Selection is completely before command prompt,
                // so deletion is not allowed.
                //QApplication::beep();
                deletionAllowed = false;
            } else {

                // The selectionEnd is after the command prompt, so set
                // the selection start to the commandPromptPosition.
                selectionStart = commandPromptPosition;
                textCursor.setPosition(selectionStart);
                textCursor.setPosition(selectionStart, QTextCursor::MoveAnchor);
                setTextCursor(textCursor);
            }
        }
    }
    else
    { // if (hasSelectedText())
        // When there is no selected text, deletion is not allowed before the
        // command prompt.
        if (textCursor.position() < commandPromptPosition) {

            //QApplication::beep();
            deletionAllowed = false;
        }
    }
    return deletionAllowed;
}

//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::changeHistory()
{
    // Select the text after the last command prompt ...
    QTextCursor textCursor = this->textCursor();
    textCursor.movePosition(QTextCursor::End);
    textCursor.setPosition(commandPromptPosition(), QTextCursor::KeepAnchor);

    // ... and replace it with the history text.
    textCursor.insertText(_history.value(_historyPosition));
    textCursor.movePosition(QTextCursor::End);
    setTextCursor(textCursor);
}

//-----------------------------------------------------------------------------

void PythonQtScriptingConsole::consoleMessage(const QString & message) {

    append(QString(""));
    insertPlainText(message);

    // Reset all font modifications done by the html string
    setCurrentCharFormat(_defaultTextCharacterFormat);
}

// XXX CaRLo
bool PythonQtScriptingConsole::canInsertFromMimeData( const QMimeData *source ) const
{
    if (source->hasText())
        return true;
    else
        return true;
}

void PythonQtScriptingConsole::insertFromMimeData(const QMimeData *source)
{
    if (source->hasText())
    {
        //moveCursorToEndLine();
        QString code = source->text();
        if ( !code.contains("\n") || code.trimmed().endsWith(":") )
        {
            this->insertPlainText(code);
            //moveCursorToEndLine();
            return;
        }

        if (!code.isEmpty())
        {
            // Update the history
            _history << code;
            _historyPosition = _history.count();
            _currentMultiLineCode = code ;
            QStringList codeline = code.split("\n");
            for (int i=0; i<codeline.size();i++)
            {
                // put visible cursor to the end of the line
                if ( i==0 )
                {
                    this->insertPlainText(codeline[i]);
                }
                else
                    this->append(codeline[i]);
                moveCursorToEndLine();
                //emit cursorPositionChanged();
            }
            executeCode(_currentMultiLineCode);
            _currentMultiLineCode = "";
            // Select the text from the command prompt until the end of the block
            // and get the selected text.
            appendCommandPrompt(0);
            QTextCursor textCursor = this->textCursor();
            textCursor.movePosition(QTextCursor::End);
            emit commandExecuted();
        }
        this->repaint();
    }
}

void PythonQtScriptingConsole::moveCursorToEndLine()
{
    QTextCursor textCursor = this->textCursor();
    textCursor.setPosition(commandPromptPosition());
    textCursor.movePosition(QTextCursor::End,QTextCursor::KeepAnchor);
    textCursor.clearSelection();
    this->setTextCursor(textCursor);
    this->repaint();
    this->setFocus();
}

// XXX carlo, serve ad eliminare dal display del completamento i metodi indesiderati
void PythonQtScriptingConsole::setInvisibleCompletitionMethods(const QStringList &invisible)
{
    this->invisibleCompletitionMethods = invisible;
}
