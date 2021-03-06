#! /bin/sh
AM_VERSION=-`automake --version | head -n 1 | awk '{ print $NF }' | cut -d"." -f1,2`
AC_VERSION=

set -x

if [ "x${ACLOCAL_DIR}" != "x" ]; then
  ACLOCAL_ARG=-I ${ACLOCAL_DIR}
fi

${ACLOCAL:-aclocal$AM_VERSION} ${ACLOCAL_ARG}
${AUTOHEADER:-autoheader$AC_VERSION}
AUTOMAKE=${AUTOMAKE:-automake$AM_VERSION} libtoolize -c --automake
${AUTOMAKE:-automake$AM_VERSION} --add-missing --copy --include-deps
${AUTOCONF:-autoconf$AC_VERSION}

# mkinstalldirs was not correctly installed in some cases.
cp -f /usr/share/automake${AM_VERSION}/mkinstalldirs .

rm -rf autom4te.cache
