#include <obs-module.h>

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("timed-source-plugin", "en-US")

extern struct obs_source_info timed_media_source;

bool obs_module_load(void)
{
    obs_register_source(&timed_media_source);
    return true;
}