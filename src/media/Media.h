#pragma once
#include <QObject>
#include <QString>


class Media : public QObject
{


    //QObject

public:

    enum class MediaMode
    {
        Tuner,
        Spotify,
        Bluetooth

    };
    Q_ENUM(MediaMode)



    explicit Media(QObject *parent = nullptr);

    int track() const;
    void setTrack(int track);

    int volume() const;
    void setVolume(int volume);

    MediaMode mediaMode() const;
    void setMediaMode(MediaMode mediaMode);



private:
    int m_track;
    int m_volume;
    MediaMode m_mediaMode = MediaMode::Spotify;


signals:
    void trackChanged();
    void volumeChanged();
    void mediaModeChanged();



};
