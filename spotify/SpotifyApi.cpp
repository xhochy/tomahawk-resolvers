

#include "SpotifyApi.h"


#include <libspotify/api.h>
#include <QDebug>
#include <QLibrary>

#ifdef _WIN32
#include <wtypes.h>
#else
#include <dlfcn.h>
#endif

SpotifyApi* SpotifyApi::s_instance = 0;

SpotifyApi*
SpotifyApi::instance()
{
    if ( !s_instance )
        s_instance = new SpotifyApi();

    return s_instance;
}

#ifdef _WIN32
#define spotify_symbol_name(symbol, number) "_sp_" #symbol "@" #number
#else
#define spotify_symbol_name(symbol, number) "sp_" #symbol
#endif

#define resolve_spotify_symbol(symbol, number) \
        { \
            QString symbol_name = spotify_symbol_name(symbol, number); \
            f_##symbol = (sp_##symbol##_t) m_spotifyLibrary.resolve( symbol_name.toAscii().data() );\
            if( f_##symbol == NULL ) \
            { \
                qDebug() << #symbol << m_spotifyLibrary.errorString(); \
                qFatal( QString("loading %1 failed").arg(symbol_name).toAscii().data() ); \
            } \
            else \
            { \
               qDebug() << symbol_name << "loaded"; \
            } \
        }



SpotifyApi::SpotifyApi()
    : m_spotifyLibrary("libspotify")
{
    qDebug() << "Try to load libspotify.dll ...";
    if( !m_spotifyLibrary.load() )
        qFatal("loading spotify failed");
    qDebug() << "loading library succeeded, go on";

    //session
    resolve_spotify_symbol(session_create, 8);
    resolve_spotify_symbol(session_login, 20);
    resolve_spotify_symbol(session_logout, 4);
    resolve_spotify_symbol(session_player_load, 8);
    resolve_spotify_symbol(session_player_play, 8);
    resolve_spotify_symbol(session_player_unload, 4);
    resolve_spotify_symbol(session_userdata, 4);
    resolve_spotify_symbol(session_preferred_bitrate, 8);
    resolve_spotify_symbol(session_process_events, 8);
    resolve_spotify_symbol(session_user, 4);
    resolve_spotify_symbol(session_starred_create, 4);
    resolve_spotify_symbol(session_playlistcontainer, 4);
    resolve_spotify_symbol(session_connectionstate, 4);

    // error
    resolve_spotify_symbol(error_message, 4);

    // artist
    resolve_spotify_symbol(artist_name, 4);
    resolve_spotify_symbol(artist_is_loaded, 4);

    // track
    resolve_spotify_symbol(track_album, 4);
    resolve_spotify_symbol(track_artist, 8);
    resolve_spotify_symbol(track_duration, 4);
    resolve_spotify_symbol(track_name, 4);
    resolve_spotify_symbol(track_is_loaded, 4);
    resolve_spotify_symbol(track_index, 4);
    resolve_spotify_symbol(track_disc, 4);
    resolve_spotify_symbol(track_release, 4);
    resolve_spotify_symbol(track_add_ref, 4);

    // album
    resolve_spotify_symbol(album_name, 4);
    resolve_spotify_symbol(album_year, 4);
    resolve_spotify_symbol(album_is_loaded, 4);

    // playlist
    resolve_spotify_symbol(playlist_is_loaded, 4);
    resolve_spotify_symbol(playlist_name, 4);
    resolve_spotify_symbol(playlist_add_tracks, 20);
    resolve_spotify_symbol(playlist_num_tracks, 4);
    resolve_spotify_symbol(playlist_add_callbacks, 12);
    resolve_spotify_symbol(playlist_add_ref, 4);
    resolve_spotify_symbol(playlist_remove_callbacks, 12);
    resolve_spotify_symbol(playlist_track, 8);
    resolve_spotify_symbol(playlist_track_create_time, 8);
    resolve_spotify_symbol(playlist_is_collaborative, 4);
    resolve_spotify_symbol(playlist_remove_tracks, 12);
    resolve_spotify_symbol(playlist_rename, 8);
    resolve_spotify_symbol(playlist_reorder_tracks, 16);
    resolve_spotify_symbol(playlist_release, 4);
    resolve_spotify_symbol(playlist_create, 8);
    resolve_spotify_symbol(playlist_set_collaborative, 8);

    // playlistcontainer
    resolve_spotify_symbol(playlistcontainer_remove_callbacks, 12);
    resolve_spotify_symbol(playlistcontainer_playlist_type, 8);
    resolve_spotify_symbol(playlistcontainer_num_playlists, 4);
    resolve_spotify_symbol(playlistcontainer_add_new_playlist, 8);
    resolve_spotify_symbol(playlistcontainer_remove_playlist, 8);
    resolve_spotify_symbol(playlistcontainer_playlist, 8);
    resolve_spotify_symbol(playlistcontainer_add_ref, 4);
    resolve_spotify_symbol(playlistcontainer_release, 4);
    resolve_spotify_symbol(playlistcontainer_add_callbacks, 12);


    // link
    resolve_spotify_symbol(link_type, 4);
    resolve_spotify_symbol(link_as_track, 4);
    resolve_spotify_symbol(link_create_from_string, 4);
    resolve_spotify_symbol(link_create_from_track, 8);
    resolve_spotify_symbol(link_as_string, 12);
    resolve_spotify_symbol(link_release, 4);

    // search
    resolve_spotify_symbol(search_num_tracks, 4);
    resolve_spotify_symbol(search_track, 8);
    resolve_spotify_symbol(search_did_you_mean, 4);
    resolve_spotify_symbol(search_query, 4);
    resolve_spotify_symbol(search_create, 52);
    resolve_spotify_symbol(search_release, 4);

    // user
    resolve_spotify_symbol(user_canonical_name, 4);
}


SpotifyApi::~SpotifyApi()
{
    m_spotifyLibrary.unload();
}
