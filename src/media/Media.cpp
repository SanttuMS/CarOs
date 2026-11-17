#include "Media.h"

Media::Media(QObject *parent)
    : QObject(parent)
{
}

bool Media::isPlaying() const
{
    return m_isPlaying;
}

QString Media::currentTrack() const
{
    return m_currentTrack;
}

int Media::volume() const
{
    return m_volume;
}

Media::MediaMode Media::mediaMode() const
{
    return m_mediaMode;
}

QString Media::artist() const
{
    return m_artist;
}

void Media::playPause()
{
    setPlaying(!m_isPlaying);
}


void Media::setPlaying(bool isPlaying)
{
    if (m_isPlaying == isPlaying)
        return;

    m_isPlaying = isPlaying;
    emit playingChanged();
}

void Media::setCurrentTrack(const QString &currentTrack)
{
    if(m_currentTrack == currentTrack)
        return;

    m_currentTrack = currentTrack;
    emit currentTrackChanged();
}

void Media::setVolume(int volume)
{
    if(m_volume == volume)
        return;

    m_volume = volume;
    emit volumeChanged();
}

void Media::setMediaMode(MediaMode mediaMode)
{
    if(m_mediaMode == mediaMode)
        return;

    m_mediaMode = mediaMode;
    emit mediaModeChanged();
}

void Media::setArtist(const QString &artist)
{
    if(m_artist == artist)
        return;

    m_artist = artist;
    emit artistChanged();
}

void Media::nextTrack()
{
    if (m_tracks.isEmpty())
        return;

    m_trackIndex++;


    if(m_trackIndex >= m_tracks.size())
        m_trackIndex = 0;

    setCurrentTrack(m_tracks[m_trackIndex]);
}

void Media::previousTrack()
{
    if (m_tracks.isEmpty())
        return;

    m_trackIndex--;


    if(m_trackIndex < 0)
        m_trackIndex = m_tracks.size() - 1;

    setCurrentTrack(m_tracks[m_trackIndex]);
}

void Media::setTuner()
{
    setMediaMode(MediaMode::Tuner);
}

void Media::setBluetooth()
{
    setMediaMode(MediaMode::Bluetooth);
}

void Media::setSpotify()
{
    setMediaMode(MediaMode::Spotify);
}

QString Media::mediaModeText() const
{

    switch(m_mediaMode){
    case MediaMode::Tuner:
        return "TUNER";

    case MediaMode::Spotify:
        return "SPOTIFY";

    case MediaMode::Bluetooth:
        return "BLUETOOTH";
    }

    return "UNKNOWN";
}

