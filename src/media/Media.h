#pragma once
#include <QObject>
#include <QString>
#include <QStringList>


class Media : public QObject
{


    Q_OBJECT

    Q_PROPERTY(QString currentTrack READ currentTrack WRITE setCurrentTrack NOTIFY currentTrackChanged)
    Q_PROPERTY(int  volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(MediaMode mediaMode READ mediaMode WRITE setMediaMode NOTIFY mediaModeChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString mediaModeText READ mediaModeText NOTIFY mediaModeChanged)


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
    Q_INVOKABLE void nextTrack();
    Q_INVOKABLE void previousTrack();


    explicit Media(QObject *parent = nullptr);

    QString currentTrack() const;
    void setCurrentTrack(const QString &currentTrack);

    //void nextTrack(const QString &currentTrack);
    //void previousTrack(const QString &currentTrack);


    int volume() const;
    void setVolume(int volume);

    MediaMode mediaMode() const;
    void setMediaMode(MediaMode mediaMode);

    QString artist() const;
    void setArtist(const QString &artist);

    bool isPlaying() const;
    void setPlaying(bool isPlaying);

    QString mediaModeText() const;





signals:
    void currentTrackChanged();
    void volumeChanged();
    void mediaModeChanged();
    void artistChanged();
    void playingChanged();


private:
    int m_trackIndex = 0;
    int m_artistIndex = 0;
    QStringList m_tracks = {
        "Perhonen",
        "Luotathan",
        "Feimii",
        "Aino"
    };
    QStringList m_artists = {
        "Lauri Haav",
    };
    int m_volume = 50;
    bool m_isPlaying = false;
    //QString m_artist;
    QString m_currentTrack;
    QString m_artist;
    MediaMode m_mediaMode = MediaMode::Spotify;




};
