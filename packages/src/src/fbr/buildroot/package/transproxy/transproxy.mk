TRANSPROXY_VERSION = 1.6
TRANSPROXY_SOURCE  = transproxy-$(TRANSPROXY_VERSION).tgz
TRANSPROXY_SITE    = http://downloads.sourceforge.net/project/transproxy/transproxy/$(TRANSPROXY_VERSION)

TRANSPROXY_DEPENDENCIES =

TRANSPROXY_LICENSE = BSD-like
TRANSPROXY_LICENSE_FILES = COPYRIGHT

define TRANSPROXY_BUILD_CMDS
	+$(TARGET_MAKE_ENV) $(MAKE) -C $(@D) $(TARGET_CONFIGURE_OPTS)
endef

define TRANSPROXY_INSTALL_TARGET_CMDS
	$(INSTALL) -D $(@D)/tproxy $(TARGET_DIR)/usr/sbin/tproxy
endef

$(eval $(generic-package))