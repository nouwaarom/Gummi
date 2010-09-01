/**
 * @file   utils.h
 * @brief  utility for gummi
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2010 -  Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 */

#ifndef GUMMI_UTILS
#define GUMMI_UTILS

#include <glib.h>

#define L_IS_TYPE(level, type) ((level & type) == type)
#define L_IS_GUI(level) (level & 0xf0)
#define L_INFO     0x01    /* for informative messages */
#define L_DEBUG    0x02    /* debug messages, only print if -d flags is used */
#define L_ERROR    0x04    /* reconverable error */
#define L_FATAL    0x08    /* inrecoverable error */
#define L_G_INFO   0x10    /* GUI info */
#define L_G_ERROR  0x20    /* recoverable error */
#define L_G_FATAL  0x40    /* inrecoverable error */

/**
 * @brief slog initlization
 * @param debug boolean value for whether output debug message or not
 */
void slog_init(gint debug);

/**
 * @brief debug interface for gummi
 * @param level levels or listed above
 * @param fmt just like the printf function
 * @param ... parameters for fmt
 */
void slog(gint level, const gchar *fmt, ...);

gboolean utils_yes_no_dialog(const gchar* message);
gboolean utils_validate_path(const gchar* path);

#endif /* GUMMI_UTILS */
