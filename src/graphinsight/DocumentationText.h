#ifndef DOCUMENTATIONTEXTEDIT_H
 #define DOCUMENTATIONTEXTEDIT_H

 #include <QtCore/QUrl>
 #include <QtGui/QTextEdit>

 class DocumentationText : public QTextEdit
 {
     Q_OBJECT
 public:
     DocumentationText(QWidget *parent = 0);
     void setContents(const QString &fileName);
     QSize minimumSizeHint() const;
     QSize sizeHint() const;
 private:
     QVariant loadResource(int type, const QUrl &name);
     QUrl srcUrl;
 };

 #endif
