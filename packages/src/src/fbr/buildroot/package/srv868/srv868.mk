SRV868_VERSION = 1.1
SRV868_SITE = $(FLI4L_SRCDIR)/srv868
SRV868_SITE_METHOD = local
SRV868_SOURCE =

define SRV868_BUILD_CMDS
	+$(TARGET_MAKE_ENV) $(MAKE) -C $(@D) $(TARGET_CONFIGURE_OPTS)
endef

define SRV868_INSTALL_TARGET_CMDS
	$(INSTALL) -D $(@D)/srv868 $(TARGET_DIR)/usr/sbin/srv868
endef

$(eval $(generic-package))