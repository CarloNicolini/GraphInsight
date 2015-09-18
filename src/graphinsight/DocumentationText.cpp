#include <QtCore/QFileInfo>
#include <QtCore/QFile>
#include "DocumentationText.h"

DocumentationText::DocumentationText(QWidget *parent)
    : QTextEdit(parent)
{
    setReadOnly(true);
    setAcceptRichText(true);
}

void DocumentationText::setContents(const QString &fileName)
{
    QFileInfo fi(fileName);
    srcUrl = QUrl::fromLocalFile(fi.absoluteFilePath());
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QString data(file.readAll());
        setHtml(data);
        /*
        if (fileName.endsWith(".html"))
            setHtml(data);
        else
            setPlainText(data);
            */
    }
}

QVariant DocumentationText::loadResource(int type, const QUrl &name)
{
    if (type == QTextDocument::ImageResource) {
        QFile file(srcUrl.resolved(name).toLocalFile());
        if (file.open(QIODevice::ReadOnly))
            return file.readAll();
    }
    return QTextEdit::loadResource(type, name);
}

QSize DocumentationText::minimumSizeHint() const
{
    return QSize(240, 120);
}

QSize DocumentationText::sizeHint() const
{
    return QSize(240, 640);
}
