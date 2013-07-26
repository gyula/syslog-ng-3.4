#include "cfg-parser.h"
#include "plugin.h"

extern CfgParser afmysql_parser;

static Plugin afmysql_plugins[] =
{
  {
    .type = LL_CONTEXT_DESTINATION,
    .name = "mysql",
    .parser = &afmysql_parser,
  },
};

gboolean
afmysql_module_init(GlobalConfig *cfg, CfgArgs *args)
{
  plugin_register(cfg, afmysql_plugins, G_N_ELEMENTS(afmysql_plugins));
  return TRUE;
}

const ModuleInfo module_info =
{
  .canonical_name = "afmysql",
  .version = VERSION,
  .description = "The afmysql module provides MySQL destination support for syslog-ng",
  .core_revision = SOURCE_REVISION,
  .plugins = afmysql_plugins,
  .plugins_len = G_N_ELEMENTS(afmysql_plugins),
};
