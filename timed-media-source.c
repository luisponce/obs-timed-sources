#include <obs-module.h>

struct timed_media_source {
	ffmpeg_source *media_source;
};

static const char *timed_media_source_getname(void* unused)
{
	UNUSED_PARAMETER(unused);
	return obs_module_text("TimedMediaSource");
}

static void *timed_media_source_create(obs_data_t *settings, obs_source_t *source)
{
	struct ffmpeg_source *tms = bzalloc(sizeof(struct timed_media_source));
	tms->media_source = ffmpeg_source_create(settings, source);

	return tms;
}

static void timed_media_source_destroy(void *data)
{
	struct timed_media_source *s = data;

	ffmpeg_source_destroy(s->media_source);
	
	bfree(s);
}

static void timed_media_source_defaults(obs_data_t *settings)
{
	ffmpeg_source_defaults(settings);
}

static obs_properties_t *timed_media_source_getproperties(void *data)
{
	struct timed_media_source *s = data;

	return ffmpeg_source_getproperties(s->media_source);
}

static void timed_media_source_activate(void *data)
{
	struct timed_media_source *s = data;

	ffmpeg_source_activate(s->media_source);
}

static void timed_media_source_deactivate(void *data)
{
	struct timed_media_source *s = data;

	ffmpeg_source_deactivate(s->media_source);
}

static void timed_media_source_tick(void *data, float seconds)
{
	struct timed_media_source *s = data;

	ffmpeg_source_tick(s->media_source, seconds);
}

static void timed_media_source_update(void *data, obs_data_t *settings)
{
	struct timed_media_source *s = data;

	ffmpeg_source_update(s->media_source, settings);
}

static void timed_media_source_play_pause(void *data, bool pause)
{
	struct timed_media_source *s = data;

	ffmpeg_source_play_pause(s->media_source, pause);
}

static void timed_media_source_restart(void *data)
{
	struct timed_media_source *s = data;

	ffmpeg_source_restart(s->media_source);
}

static void timed_media_source_stop(void *data)
{
	struct timed_media_source *s = data;

	ffmpeg_source_stop(s->media_source);
}

static int64_t timed_media_source_get_duration(void *data)
{
	struct timed_media_source *s = data;

	return ffmpeg_source_get_duration(s->media_source);
}

static int64_t timed_media_source_get_time(void *data)
{
	struct timed_media_source *s = data;

	return ffmpeg_source_get_time(s->media_source);
}

static void timed_media_source_set_time(void *data, int64_t ms)
{
	struct timed_media_source *s = data;

	ffmpeg_source_set_time(s->media_source, ms);
}

static enum obs_media_state timed_media_source_get_state(void *data)
{
	struct timed_media_source *s = data;

	return ffmpeg_source_get_state(s->media_source);
}

struct obs_source_info timed_media_source = {
	.id = "timed_media_source",
	.type = OBS_SOURCE_TYPE_INPUT,
	.output_flags = OBS_SOURCE_ASYNC_VIDEO | OBS_SOURCE_AUDIO |
			OBS_SOURCE_DO_NOT_DUPLICATE |
			OBS_SOURCE_CONTROLLABLE_MEDIA,
	.get_name = timed_media_source_getname,
	.create = timed_media_source_create,
	.destroy = timed_media_source_destroy,
	.get_defaults = timed_media_source_defaults,
	.get_properties = timed_media_source_getproperties,
	.activate = timed_media_source_activate,
	.deactivate = timed_media_source_deactivate,
	.video_tick = timed_media_source_tick,
	.update = timed_media_source_update,
	.icon_type = OBS_ICON_TYPE_MEDIA,
	.media_play_pause = timed_media_source_play_pause,
	.media_restart = timed_media_source_restart,
	.media_stop = timed_media_source_stop,
	.media_get_duration = timed_media_source_get_duration,
	.media_get_time = timed_media_source_get_time,
	.media_set_time = timed_media_source_set_time,
	.media_get_state = timed_media_source_get_state,
};