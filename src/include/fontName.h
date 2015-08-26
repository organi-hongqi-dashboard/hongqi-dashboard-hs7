#include <QFile>
#include <unistd.h>
#include <QDebug>
#include <QObject>
#include <QFontDatabase>

class MFontName : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fontCurrent READ fontCurrent NOTIFY fontCurrentChanged)

signals:
    // fonts
    void fontCurrentChanged(QString);

public:
    explicit MFontName(QObject *parent = 0)
        : QObject(parent)
    {
//        #ifdef FONTS_PATH
//            m_fontDark = loadFontFamilyFromTTF("/usr/lib/fonts/darkforest.ttf");
//            m_fontWqy = loadFontFamilyFromTTF("/usr/lib/fonts/wqy-microhei.ttf");
//        #else
//            m_fontDark = loadFontFamilyFromTTF( QString(getcwd( NULL, 0 )) + "/fonts/darkforest.ttf" );
//            m_fontWqy = loadFontFamilyFromTTF( QString(getcwd( NULL, 0 )) + "/fonts/wqy-microhei.ttf" );
//        #endif

        m_fontCurrent = loadFontFamilyFromTTF("/usr/lib/fonts/MicroSoftYahei.TTF");
    }

    QString loadFontFamilyFromTTF(QString str)
    {
        static QString font;
        QFile fontFile(str);
        if(!fontFile.open(QIODevice::ReadOnly)) {
            qWarning() << "font file load fail";
            return QString();
        }
        int loadedFontID = QFontDatabase::addApplicationFontFromData(fontFile.readAll());
        QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
        if(!loadedFontFamilies.empty())
            font = loadedFontFamilies.at(0);

        fontFile.close();
        return font;
    }

    // fonts
    QString fontCurrent()const { return m_fontCurrent; }

private:
    QString m_fontCurrent;
};

//QString MFontName::loadFontFamilyFromTTF(QString str);
