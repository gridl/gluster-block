/*
  Copyright (c) 2018 Red Hat, Inc. <http://www.redhat.com>
  This file is part of gluster-block.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/


# include "block.h"
# include "common.h"


typedef struct gbCapObj {
  char cap[256];
  bool status;
} gbCapObj;


typedef struct gbCapResp {
  int capMax;
  gbCapObj *response;
} gbCapResp;


enum gbCapabilities {
  GB_CREATE_CAP,
  GB_CREATE_HA_CAP,
  GB_CREATE_PREALLOC_CAP,
  GB_CREATE_AUTH_CAP,

  GB_DELETE_CAP,
  GB_DELETE_FORCE_CAP,

  GB_MODIFY_CAP,
  GB_MODIFY_AUTH_CAP,

  GB_REPLACE_CAP,

  GB_JSON_CAP,

  GB_CAP_MAX
};


static const char *const gbCapabilitiesLookup[] = {
  [GB_CREATE_CAP]              = "create",
  [GB_CREATE_HA_CAP]           = "create_ha",
  [GB_CREATE_PREALLOC_CAP]     = "create_prealloc",
  [GB_CREATE_AUTH_CAP]         = "create_auth",

  [GB_DELETE_CAP]              = "delete",
  [GB_DELETE_FORCE_CAP]        = "delete_force",

  [GB_MODIFY_CAP]              = "modify",
  [GB_MODIFY_AUTH_CAP]         = "modify_auth",

  [GB_REPLACE_CAP]             = "replace",

  [GB_JSON_CAP]                = "json",

  [GB_CAP_MAX]                 = NULL
};


int gbCapabilitiesEnumParse(const char *cap);
int gbSetCapabilties (blockResponse **c);
