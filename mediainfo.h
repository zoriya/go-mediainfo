#include <stdlib.h>
#include <MediaInfoDLL/MediaInfoDLL.h>

void *OpenFile(char *filePath)
{
    void *handle = MediaInfo_New();
    if (!handle)
    {
        return NULL;
    }

    size_t res = MediaInfo_Open(handle, filePath);
    if (!res)
    {
        return NULL;
    }

    return handle;
}

void CloseFile(void *handle)
{
    MediaInfo_Close(handle);
    MediaInfo_Delete(handle);
}

const char *Get(void *handle, MediaInfo_stream_C streamKind, size_t StreamNumber, char *Parameter, MediaInfo_info_C KindOfInfo, MediaInfo_info_C KindOfSearch)
{
    return MediaInfo_Get(handle, streamKind, StreamNumber, Parameter, KindOfInfo, KindOfSearch);
}

const char *GetI(void *handle, MediaInfo_stream_C streamKind, size_t StreamNumber, unsigned long Parameter, MediaInfo_info_C KindOfInfo)
{
    return MediaInfo_GetI(handle, streamKind, StreamNumber, Parameter, KindOfInfo);
}

const char *Option(void *handle, char *Parameter, char *Value)
{
    return MediaInfo_Option(handle, Parameter, Value);
}

const char *Inform(void *handle, size_t Reserved)
{
    return MediaInfo_Inform(handle, Reserved);
}
