

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


#define resolve_spotify_symbol(symbol) \
        { \
            f_##symbol = (sp_##symbol##_t) m_spotifyLibrary.resolve("sp_" #symbol );\
            if( f_##symbol == NULL ) \
            { \
                qDebug() << #symbol << m_spotifyLibrary.errorString(); \
                qFatal("loading " #symbol " failed"); \
            } \
            else \
            { \
               qDebug() << #symbol << "loaded"; \
            } \
        }



SpotifyApi::SpotifyApi()
    : m_spotifyLibrary("libspotify")
{
    if( !m_spotifyLibrary.load() )
        qFatal("loading spotify failed");
    qDebug() << "loading library succeeded, go on";

    resolve_spotify_symbol(session_create);
    resolve_spotify_symbol(session_login);
    resolve_spotify_symbol(error_message);
    resolve_spotify_symbol(session_player_load);
    resolve_spotify_symbol(session_create);
    resolve_spotify_symbol(session_player_play);
    resolve_spotify_symbol(session_userdata);
    resolve_spotify_symbol(session_logout);
    resolve_spotify_symbol(session_preferred_bitrate);
    resolve_spotify_symbol(session_process_events);
    resolve_spotify_symbol(session_player_unload);
//     resolve_spotify_symbol(session_user);
//     resolve_spotify_symbol(session_starred_create);
//     resolve_spotify_symbol(session_playlistcontainer);
//     resolve_spotify_symbol(session_connectionstate);
    resolve_spotify_symbol(artist_name);
    resolve_spotify_symbol(artist_is_loaded);
    resolve_spotify_symbol(track_album);
    resolve_spotify_symbol(track_artist);
    resolve_spotify_symbol(track_duration);
    resolve_spotify_symbol(track_name);
    resolve_spotify_symbol(track_is_loaded);
    resolve_spotify_symbol(track_index);
    resolve_spotify_symbol(track_disc);
    resolve_spotify_symbol(track_release);
    resolve_spotify_symbol(track_add_ref);
    resolve_spotify_symbol(album_name);
    resolve_spotify_symbol(album_year);
    resolve_spotify_symbol(album_is_loaded);
    resolve_spotify_symbol(playlist_is_loaded);
    resolve_spotify_symbol(playlist_name);
    resolve_spotify_symbol(playlist_add_tracks);
    resolve_spotify_symbol(playlist_num_tracks);
    resolve_spotify_symbol(playlist_add_callbacks);
    resolve_spotify_symbol(playlist_add_ref);
    resolve_spotify_symbol(playlist_remove_callbacks);
    resolve_spotify_symbol(playlistcontainer_remove_callbacks);
    resolve_spotify_symbol(playlist_track);
    resolve_spotify_symbol(playlist_track_create_time);
    resolve_spotify_symbol(playlist_is_collaborative);
    resolve_spotify_symbol(playlist_remove_tracks);
    resolve_spotify_symbol(playlist_rename);
    resolve_spotify_symbol(playlist_reorder_tracks);
    resolve_spotify_symbol(playlist_release);
    resolve_spotify_symbol(playlist_create);
    resolve_spotify_symbol(playlistcontainer_playlist_type);
    resolve_spotify_symbol(playlistcontainer_num_playlists);
    resolve_spotify_symbol(playlistcontainer_add_new_playlist);
    resolve_spotify_symbol(playlistcontainer_remove_playlist);
    resolve_spotify_symbol(playlistcontainer_playlist);
    resolve_spotify_symbol(playlistcontainer_add_ref);
    resolve_spotify_symbol(playlistcontainer_release);
    resolve_spotify_symbol(playlistcontainer_add_callbacks);
    resolve_spotify_symbol(playlist_set_collaborative);
    resolve_spotify_symbol(link_type);
    resolve_spotify_symbol(link_as_track);
    resolve_spotify_symbol(link_create_from_string);
    resolve_spotify_symbol(link_create_from_track);
    resolve_spotify_symbol(link_as_string);
    resolve_spotify_symbol(link_release);
    resolve_spotify_symbol(search_num_tracks);
    resolve_spotify_symbol(search_track);
    resolve_spotify_symbol(search_did_you_mean);
    resolve_spotify_symbol(search_query);
    resolve_spotify_symbol(search_create);
    resolve_spotify_symbol(search_release);
    resolve_spotify_symbol(user_canonical_name);
}


SpotifyApi::~SpotifyApi()
{
    m_spotifyLibrary.unload();
}
