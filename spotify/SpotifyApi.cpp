

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
//     resolve_spotify_symbol(session_user);

}


SpotifyApi::~SpotifyApi()
{
    m_spotifyLibrary.unload();
}
