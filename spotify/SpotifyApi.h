/*
    Copyright (c) 2012, Dominik Schmidt <email>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY Dominik Schmidt <email> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL Dominik Schmidt <email> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef SPOTIFYAPI_H
#define SPOTIFYAPI_H

#include <libspotify/api.h>
#include <QLibrary>

/*
 * Error handling
 */
//const char* sp_error_message  (   sp_error    error    )
typedef const char* (SP_CALLCONV *sp_error_message_t)(sp_error);

/*
 * Session module
 */

//sp_error sp_session_player_load (sp_session * session, sp_track * track)
typedef sp_error (SP_CALLCONV *sp_session_player_load_t)(sp_session*, sp_track*);

//sp_error    sp_session_create (const sp_session_config *config, sp_session **sess)
typedef sp_error (SP_CALLCONV *sp_session_create_t)(sp_session_config*, sp_session**);

//void  sp_session_player_play (sp_session *session, bool play)
typedef sp_error (SP_CALLCONV *sp_session_player_play_t)(sp_session*, bool);

//void *    sp_session_userdata (sp_session *session)
typedef void* (SP_CALLCONV *sp_session_userdata_t)(sp_session*);

//void  sp_session_logout (sp_session *session)
typedef void (SP_CALLCONV *sp_session_logout_t)(sp_session*);

//void  sp_session_preferred_bitrate (sp_session *session, sp_bitrate bitrate)
typedef void (SP_CALLCONV *sp_session_preferred_bitrate_t)(sp_session*, sp_bitrate);

//void sp_session_process_events    (   sp_session *    session, int *   next_timeout)
typedef void (SP_CALLCONV *sp_session_process_events_t)(sp_session*, int*);

//void  sp_session_login (sp_session *session, const char *username, const char *password, bool remember_me, const char *blob)
typedef void (SP_CALLCONV *sp_session_login_t)(sp_session*, const char*, const char*, bool, const char*);

//void  sp_session_player_unload (sp_session *session)
typedef void (SP_CALLCONV *sp_session_player_unload_t)(sp_session*);

//sp_user *   sp_session_user (sp_session *session)
typedef sp_user* (SP_CALLCONV sp_session_user_t)(sp_session*);

//sp_playlist *   sp_session_starred_create (sp_session *session)
typedef sp_playlist* (SP_CALLCONV sp_session_starred_create_t)(sp_session*);

//sp_playlistcontainer *    sp_session_playlistcontainer (sp_session *session)
typedef sp_playlistcontainer* (SP_CALLCONV sp_session_playlistcontainer_t)(sp_session*);

//sp_connectionstate sp_session_connectionstate     (   sp_session *    session      )
typedef sp_connectionstate (SP_CALLCONV sp_session_connectionstate_t)(sp_session*);





/*
 * Artist module
 */
//const char *  sp_artist_name (sp_artist *artist)
typedef const char* (SP_CALLCONV *sp_artist_name_t)(sp_artist*);

//bool  sp_artist_is_loaded (sp_artist *artist)
typedef bool (SP_CALLCONV *sp_artist_is_loaded_t)(sp_artist*);

/*
 * Track module
 */
//sp_album *  sp_track_album (sp_track *track)
typedef sp_album* (SP_CALLCONV *sp_track_album_t)(sp_track*);

//sp_artist *   sp_track_artist (sp_track *track, int index)
typedef sp_artist* (SP_CALLCONV *sp_track_artist_t)(sp_track*, int);

//int   sp_track_duration (sp_track *track)
typedef int (SP_CALLCONV *sp_track_duration_t)(sp_track*);

//const char *  sp_track_name (sp_track *track)
typedef const char* (SP_CALLCONV *sp_track_name_t)(sp_track*);

//bool sp_track_is_loaded   (   sp_track *      track    )
typedef bool (SP_CALLCONV *sp_track_is_loaded_t)(sp_track*);

//int   sp_track_index (sp_track *track)
typedef int (SP_CALLCONV *sp_track_index_t)(sp_track*);

//int   sp_track_disc (sp_track *track)
typedef int (SP_CALLCONV *sp_track_disc_t)(sp_track*);

//void  sp_track_release (sp_track *track)
typedef void (SP_CALLCONV *sp_track_release_t)(sp_track*);

//void  sp_track_add_ref (sp_track *track)
typedef void (SP_CALLCONV *sp_track_add_ref_t)(sp_track*);


/*
 * Album module
 */
//const char *    sp_album_name (sp_album *album)
typedef const char* (SP_CALLCONV *sp_album_name_t)(sp_album*);

//int     sp_album_year (sp_album *album)
typedef int (SP_CALLCONV *sp_album_year_t)(sp_album*);

//bool  sp_album_is_loaded (sp_album *album)
typedef bool (SP_CALLCONV *sp_album_is_loaded_t)(sp_album*);


/*
 * Playlist module
 */
//bool sp_playlist_is_loaded    (   sp_playlist *   playlist     )
typedef bool (SP_CALLCONV *sp_playlist_is_loaded_t)(sp_playlist*);

//const char *  sp_playlist_name (sp_playlist *playlist)
typedef const char* (SP_CALLCONV *sp_playlist_name_t)(sp_playlist*);

//sp_error    sp_playlist_add_tracks (sp_playlist *playlist, sp_track *const *tracks, int num_tracks, int position, sp_session *session)
typedef sp_error (SP_CALLCONV *sp_playlist_add_tracks_t)(sp_playlist*, sp_track*const*,  int, int, sp_session*); //TODO: check this!

//int sp_playlist_num_tracks    (   sp_playlist *   playlist     )
typedef int (SP_CALLCONV *sp_playlist_num_tracks_t)(sp_playlist*);

//void  sp_playlist_add_callbacks (sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
typedef void (SP_CALLCONV *sp_playlist_add_callbacks_t)(sp_playlist*, sp_playlist_callbacks*, void*);

//void  sp_playlist_add_ref (sp_playlist *playlist)
typedef void (SP_CALLCONV *sp_playlist_add_ref_t)(sp_playlist*);

//void  sp_playlist_remove_callbacks (sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata)
typedef void (SP_CALLCONV *sp_playlist_remove_callbacks_t)(sp_playlist*, sp_playlist_callbacks*, void*);

// void  sp_playlistcontainer_remove_callbacks (sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
typedef void (SP_CALLCONV *sp_playlistcontainer_remove_callbacks_t)(sp_playlistcontainer*, sp_playlistcontainer_callbacks*, void*);

//sp_track *    sp_playlist_track (sp_playlist *playlist, int index)
typedef sp_track* (SP_CALLCONV *sp_playlist_track_t)(sp_playlist*,int);

//int   sp_playlist_track_create_time (sp_playlist *playlist, int index)
typedef int (SP_CALLCONV *sp_playlist_track_create_time_t)(sp_playlist*,int);

//bool  sp_playlist_is_collaborative (sp_playlist *playlist)
typedef bool (SP_CALLCONV *sp_playlist_is_collaborative_t)(sp_playlist*);

//sp_error    sp_playlist_remove_tracks (sp_playlist *playlist, const int *tracks, int num_tracks)
typedef sp_error (SP_CALLCONV *sp_playlist_remove_tracks_t)(sp_playlist*,const int*, int);

//sp_error  sp_playlist_rename (sp_playlist *playlist, const char *new_name)
typedef sp_error (SP_CALLCONV *sp_playlist_rename_t)(sp_playlist*,const char*);

//sp_error  sp_playlist_reorder_tracks (sp_playlist *playlist, const int *tracks, int num_tracks, int new_position)
typedef sp_error (SP_CALLCONV *sp_playlist_reorder_tracks_t)(sp_playlist*,const int*, int, int);

//void    sp_playlist_release (sp_playlist *playlist)
typedef void (SP_CALLCONV *sp_playlist_release_t)(sp_playlist*);

//sp_playlist *     sp_playlist_create (sp_session *session, sp_link *link)
typedef sp_playlist* (SP_CALLCONV *sp_playlist_create_t)(sp_session*, sp_link*);

//sp_playlist_type  sp_playlistcontainer_playlist_type (sp_playlistcontainer *pc, int index)
typedef sp_playlist_type (SP_CALLCONV *sp_playlistcontainer_playlist_type_t)(sp_playlistcontainer*, int);

//int   sp_playlistcontainer_num_playlists (sp_playlistcontainer *pc)
typedef int (SP_CALLCONV *sp_playlistcontainer_num_playlists_t)(sp_playlistcontainer*);

//sp_playlist *     sp_playlistcontainer_add_new_playlist (sp_playlistcontainer *pc, const char *name)
typedef sp_playlist* (SP_CALLCONV *sp_playlistcontainer_add_new_playlist_t)(sp_playlistcontainer*, const char*);

//sp_error  sp_playlistcontainer_remove_playlist (sp_playlistcontainer *pc, int index)
typedef sp_error (SP_CALLCONV *sp_playlistcontainer_remove_playlist_t)(sp_playlistcontainer*,int);

//sp_playlist *   sp_playlistcontainer_playlist (sp_playlistcontainer *pc, int index)
typedef sp_playlist* (SP_CALLCONV *sp_playlistcontainer_playlist_t)(sp_playlistcontainer*,int);

//void sp_playlistcontainer_add_ref     (   sp_playlistcontainer *      pc   )
typedef void (SP_CALLCONV *sp_playlistcontainer_add_ref_t)(sp_playlistcontainer*);

//void  sp_playlistcontainer_release (sp_playlistcontainer *pc)
typedef void (SP_CALLCONV *sp_playlistcontainer_release_t)(sp_playlistcontainer*);

//void  sp_playlistcontainer_add_callbacks (sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata)
typedef void (SP_CALLCONV *sp_playlistcontainer_add_callbacks_t)(sp_playlistcontainer*,sp_playlistcontainer_callbacks*,void*);

//void    sp_playlist_set_collaborative (sp_playlist *playlist, bool collaborative)
typedef void (SP_CALLCONV *sp_playlist_set_collaborative_t)(sp_playlist*,bool);

/*
 * Links module
 */
//sp_linktype   sp_link_type (sp_link *link)
typedef sp_linktype (SP_CALLCONV *sp_link_type_t)(sp_link*);

//sp_track *  sp_link_as_track (sp_link *link)
typedef sp_track* (SP_CALLCONV *sp_link_as_track_t)(sp_link*);

//sp_link *   sp_link_create_from_string (const char *link)
typedef sp_link* (SP_CALLCONV *sp_link_create_from_string_t)(char*);

//sp_link *     sp_link_create_from_track (sp_track *track, int offset)
typedef sp_link* (SP_CALLCONV *sp_link_create_from_track_t)(sp_track*, int offset);

//int     sp_link_as_string (sp_link *link, char *buffer, int buffer_size)
typedef int (SP_CALLCONV *sp_link_as_string_t)(sp_link*, char*, int);

//void sp_link_release(sp_link *link);
typedef void (SP_CALLCONV *sp_link_release_t)(sp_link*);

/*
 * Search module
 */
//int     sp_search_num_tracks (sp_search *search)
typedef int (SP_CALLCONV *sp_search_num_tracks_t)(sp_search*);

//sp_track *    sp_search_track (sp_search *search, int index)
typedef sp_track* (SP_CALLCONV *sp_search_track_t)(sp_search*,int);

//const char *  sp_search_did_you_mean (sp_search *search);
typedef const char* (SP_CALLCONV *sp_search_did_you_mean_t)(sp_search*);

//const char* sp_search_query   (   sp_search *     search   )
typedef const char* (SP_CALLCONV *sp_search_query_t)(sp_search*);

//sp_search *   sp_search_create (sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata)
typedef sp_search* (SP_CALLCONV *sp_search_create_t)(sp_session*, const char*, int, int, int, int, int, int, int, int, sp_search_type, search_complete_cb*, void*);

//void  sp_search_release (sp_search *search)
typedef void (SP_CALLCONV *sp_search_release_t)(sp_search*);

/*
 * USER module
 */

//const char *    sp_user_canonical_name (sp_user *user)
typedef const char* (SP_CALLCONV *sp_user_canonical_name_t)(sp_user*);


#ifdef _WIN32
#include <wtypes.h>
#endif

class SpotifyApi
{

public:
    static SpotifyApi* instance();
    virtual ~SpotifyApi();

    sp_link_create_from_string_t f_link_create_from_string;
    sp_session_create_t f_session_create;
    sp_link_as_track_t f_link_as_track;
    sp_link_type_t f_link_type;
    sp_track_is_loaded_t f_track_is_loaded;
    sp_track_name_t f_track_name;
    sp_track_duration_t f_track_duration;
    sp_track_artist_t f_track_artist;
    sp_artist_name_t f_artist_name;
    sp_session_player_load_t f_session_player_load;
    sp_error_message_t f_error_message;
    sp_session_player_play_t f_session_player_play;
    sp_album_name_t f_album_name;
    sp_track_album_t f_track_album;
    sp_playlist_name_t f_playlist_name;
    sp_playlist_is_loaded_t f_playlist_is_loaded;
    sp_session_userdata_t f_session_userdata;
    sp_search_num_tracks_t f_search_num_tracks;
    sp_search_track_t f_search_track;
    sp_playlist_add_tracks_t f_playlist_add_tracks;
    sp_playlist_num_tracks_t f_playlist_num_tracks;
    sp_link_create_from_track_t f_link_create_from_track;
    sp_search_did_you_mean_t f_search_did_you_mean;
    sp_search_query_t f_search_query;
    sp_search_create_t f_search_create;
    sp_search_release_t f_search_release;
    sp_session_logout_t f_session_logout;
    sp_session_preferred_bitrate_t f_session_preferred_bitrate;
    sp_session_process_events_t f_session_process_events;
    sp_link_as_string_t f_link_as_string;
    sp_session_login_t f_session_login;
    sp_link_release_t f_link_release;
    sp_playlist_add_callbacks_t f_playlist_add_callbacks;
    sp_playlist_add_ref_t f_playlist_add_ref;
    sp_playlist_track_t f_playlist_track;
    sp_playlist_track_create_time_t f_playlist_track_create_time;
    sp_playlist_is_collaborative_t f_playlist_is_collaborative;
    sp_playlist_remove_tracks_t f_playlist_remove_tracks;
    sp_playlist_rename_t f_playlist_rename;
    sp_playlist_remove_callbacks_t f_playlist_remove_callbacks;
    sp_playlist_reorder_tracks_t f_playlist_reorder_tracks;
    sp_playlist_release_t f_playlist_release;
    sp_playlistcontainer_playlist_type_t f_playlistcontainer_playlist_type;
    sp_playlist_create_t f_playlist_create;
    sp_playlistcontainer_num_playlists_t f_playlistcontainer_num_playlists;
    sp_playlistcontainer_add_new_playlist_t f_playlistcontainer_add_new_playlist;
    sp_playlistcontainer_remove_playlist_t f_playlistcontainer_remove_playlist;
    sp_playlistcontainer_playlist_t f_playlistcontainer_playlist;
    sp_playlistcontainer_remove_callbacks_t f_playlistcontainer_remove_callbacks;
    sp_playlistcontainer_add_ref_t f_playlistcontainer_add_ref;
    sp_playlistcontainer_add_callbacks_t f_playlistcontainer_add_callbacks;
    sp_playlistcontainer_release_t f_playlistcontainer_release;
    sp_session_player_unload_t f_session_player_unload;
    sp_track_index_t f_track_index;
    sp_track_disc_t f_track_disc;
    sp_album_year_t f_album_year;
    sp_track_release_t f_track_release;
    sp_session_user_t f_session_user;
    sp_session_starred_create_t f_session_starred_create;
    sp_playlist_set_collaborative_t f_playlist_set_collaborative;
    sp_track_add_ref_t f_track_add_ref;
    sp_session_playlistcontainer_t f_session_playlistcontainer;
    sp_session_connectionstate_t f_session_connectionstate;
    sp_artist_is_loaded_t f_artist_is_loaded;
    sp_album_is_loaded_t f_album_is_loaded;
    sp_user_canonical_name_t f_user_canonical_name;

private:
    SpotifyApi();
    QLibrary m_spotifyLibrary;

    static SpotifyApi* s_instance;
};

#endif // SPOTIFYAPI_H
