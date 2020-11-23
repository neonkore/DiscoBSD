# Generic ARM toolchain on OpenBSD
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# You can install the arm-none-eabi package, Linaro version, via:
#   $ doas pkg_add arm-none-eabi-gcc-linaro
# This also installs binutils and newlib for arm-none-eabi target.
# You can install gdb for arm-none-eabi via:
#   $ doas pkg_add arm-none-eabi-gdb
# Note that the arm-none-eabi version of gdb currently (as of OpenBSD 6.6)
# conflicts with the standard version of gdb from the ports tree,
# so choose only one to install on your system at a time.
ifndef ARM_GCC_PREFIX
    ifeq (/usr/local/bin/arm-none-eabi-gcc,$(wildcard /usr/local/bin/arm-none-eabi-gcc))
        ARM_GCC_PREFIX = /usr/local/bin/arm-none-eabi-
    endif
# Generic ARM toolchain on Linux
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ifeq (/usr/bin/arm-none-eabi-gcc,$(wildcard /usr/bin/arm-none-eabi-gcc))
        ARM_GCC_PREFIX = /usr/bin/arm-none-eabi-
    endif
endif
