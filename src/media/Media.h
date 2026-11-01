#pragma once
#include <QObject>
#include <QString>


class Media : public QObject
{


    Q_OBJECT

    Q_PROPERTY(QString currentTrack READ currentTrack WRITE setCurrentTrack NOTIFY currentTrackChanged)
    Q_PROPERTY(int  volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(MediaMode mediaMode READ mediaMode WRITE setMediaMode NOTIFY mediaModeChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setPlaying NOTIFY playingChanged)

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
    Q_INVOKABLE void playPause();


    explicit Media(QObject *parent = nullptr);

    QString currentTrack() const;
    void setCurrentTrack(const QString &currentTrack);

    int volume() const;
    void setVolume(int volume);

    MediaMode mediaMode() const;
    void setMediaMode(MediaMode mediaMode);

    QString artist() const;
    void setArtist(const QString &artist);

    bool isPlaying() const;
    void setPlaying(bool isPlaying);






signals:
    void currentTrackChanged();
    void volumeChanged();
    void mediaModeChanged();
    void artistChanged();
    void nextTrack();
    void previousTrack();
    void playingChanged();


private:
    //int m_track;
    int m_volume = 50;
    bool m_isPlaying = false;
    QString m_artist;
    QString m_currentTrack;
    MediaMode m_mediaMode = MediaMode::Spotify;



};
