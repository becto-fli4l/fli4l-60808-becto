GUTENPRINT_VERSION_MAJOR = 5.2
GUTENPRINT_VERSION = $(GUTENPRINT_VERSION_MAJOR).11
GUTENPRINT_SITE = http://downloads.sourceforge.net/project/gimp-print/gutenprint-$(GUTENPRINT_VERSION_MAJOR)/$(GUTENPRINT_VERSION)
GUTENPRINT_SOURCE = gutenprint-$(GUTENPRINT_VERSION).tar.bz2
GUTENPRINT_LICENSE = GPL-2.0+
GUTENPRINT_LICENSE_FILES = COPYING

# Needed, as we touch Makefile.am and configure.ac
GUTENPRINT_AUTORECONF = YES

GUTENPRINT_DEPENDENCIES = \
	cups host-pkgconf host-flex host-bison \
	$(if $(BR2_PACKAGE_LIBICONV),libiconv) \
	$(if $(BR2_PACKAGE_LIBUSB),libusb)

define GUTENPRINT_AUTORECONF
	cd $(@D) && $(HOST_MAKE_ENV) NOCONFIGURE=1 sh ./autogen.sh
endef
GUTENPRINT_PRE_CONFIGURE_HOOKS += GUTENPRINT_AUTORECONF

GUTENPRINT_CONF_ENV = \
	ac_cv_path_CUPS_CONFIG=$(STAGING_DIR)/usr/bin/cups-config \
	ac_cv_path_IJS_CONFIG=""

GUTENPRINT_CONF_OPTS = \
	--disable-libgutenprintui2 \
	--disable-samples \
	--without-doc \
	--without-gimp2 \
	--without-foomatic \
	--without-foomatic3 \
	--without-ghostscript \
	--without-modules \
	--without-readline \
	--enable-escputil \
	--disable-test \
	--disable-testpattern \
	--without-cups \
	--with-sysroot="$(STAGING_DIR)" \
	--disable-cups-ppds

# USE_PREGEN_XMLI18N_TMP_H is added by our patch
GUTENPRINT_MAKE_ENV = BR2_USE_PREGEN_XMLI18N_TMP_H=$(HOST_DIR)/include/xmli18n-tmp.h

HOST_GUTENPRINT_DEPENDENCIES = host-pkgconf
# The host-gutenprint shall create the required header
HOST_GUTENPRINT_MAKE_ENV =

# Even with --without-cups, gutenprint will still add the output of
# cups-config --cflags / --ldflags to it's compiler/linker flags if
# available on host.
# Notice: Because of the configure logic, it needs to be set to the
# empty string to to disable this, not just to /bin/false like elsewhere.
HOST_GUTENPRINT_CONF_ENV = ac_cv_path_CUPS_CONFIG=''

HOST_GUTENPRINT_CONF_OPTS = \
	--disable-libgutenprintui2 \
	--disable-samples \
	--without-gimp2 \
	--without-doc \
	--disable-nls \
	--disable-nls-macos \
	--without-foomatic \
	--without-foomatic3 \
	--disable-escputil \
	--disable-test \
	--disable-testpattern \
	--without-cups

# Needed by autoreconf
define GUTENPRINT_CREATE_M4_DIR
	mkdir -p $(@D)/m4local
endef
GUTENPRINT_POST_PATCH_HOOKS += GUTENPRINT_CREATE_M4_DIR
HOST_GUTENPRINT_POST_PATCH_HOOKS += GUTENPRINT_CREATE_M4_DIR

define HOST_GUTENPRINT_POST_BUILD_INSTAL_TMP_HEADER
	cp $(@D)/src/xml/xmli18n-tmp.h $(HOST_DIR)/include
endef
HOST_GUTENPRINT_POST_BUILD_HOOKS += HOST_GUTENPRINT_POST_BUILD_INSTAL_TMP_HEADER

define GUTENPRINT_POST_INSTALL_TARGET_FIXUP
	mkdir -p $(TARGET_DIR)/usr/share/gutenprint/5.2
	cp -rf $(HOST_DIR)/share/gutenprint/5.2/xml $(TARGET_DIR)/usr/share/gutenprint/5.2
endef
GUTENPRINT_POST_INSTALL_TARGET_HOOKS += GUTENPRINT_POST_INSTALL_TARGET_FIXUP

$(eval $(autotools-package))
