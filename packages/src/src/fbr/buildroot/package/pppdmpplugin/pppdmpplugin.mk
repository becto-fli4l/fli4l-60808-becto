PPPDMPPLUGIN_VERSION =
PPPDMPPLUGIN_SITE = $(FLI4L_SRCDIR)/base/pppdmpplugin
PPPDMPPLUGIN_SITE_METHOD = local
PPPDMPPLUGIN_SOURCE =
PPPDMPPLUGIN_DEPENDENCIES = pppd

define PPPDMPPLUGIN_BUILD_CMDS
	+$(TARGET_MAKE_ENV) $(MAKE) -C $(@D) $(TARGET_CONFIGURE_OPTS) \
		PPPD_BUILDDIR="$(PPPD_BUILDDIR)"
endef

define PPPDMPPLUGIN_INSTALL_TARGET_CMDS
	$(INSTALL) -D $(@D)/mp-plugin.so $(TARGET_DIR)/usr/lib/pppd/$(PPPD_VERSION)/mp-plugin.so
endef

$(eval $(generic-package))
