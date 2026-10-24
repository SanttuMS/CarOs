#include "Media.h"

Media::Media(QObject *parent)
    : QObject(parent)
{
}

int Media::track() const
{
    return m_track;
}

int Media::volume() const
{
    return m_volume;
}

Media::MediaMode Media::mediaMode() const
{
    return m_mediaMode;
}

void Media::setVolume(int volume)
{
    if(m_volume == volume)
        return;

    m_volume = volume;
    emit volumeChanged();
}

void Media::setTrack(int track)
{
    if(m_track == track)
        return;

    m_track = track;
    emit trackChanged();
}

void Media::setMediaMode(MediaMode mediaMode)
{
    if(m_mediaMode == mediaMode)
        return;

    m_mediaMode = mediaMode;
    emit mediaModeChanged();
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