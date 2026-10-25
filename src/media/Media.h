#pragma once
#include <QObject>
#include <QString>


class Media : public QObject
{


    Q_OBJECT

    Q_PROPERTY(int track READ track WRITE setTrack NOTIFY trackChanged)
    Q_PROPERTY(int  volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(MediaMode mediaMode READ mediaMode WRITE setMediaMode NOTIFY mediaModeChanged)

public:

    enum class MediaMode
    {
        Tuner,
        Spotify,
        Bluetooth

    };
    Q_ENUM(MediaMode)

    Q_INVOKABLE void setTuner();
    Q_INVOKABLE void setSpotify();
    Q_INVOKABLE void setBluetooth();



    explicit Media(QObject *parent = nullptr);

    int track() const;
    void setTrack(int track);

    int volume() const;
    void setVolume(int volume);

    MediaMode mediaMode() const;
    void setMediaMode(MediaMode mediaMode);




signals:
    void trackChanged();
    void volumeChanged();
    void mediaModeChanged();

private:
    int m_track;
    int m_volume;
    MediaMode m_mediaMode = MediaMode::Spotify;



};
