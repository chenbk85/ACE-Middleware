#### This script is meant to be sourced by ltconfig.

# $Id$

# ltcf-cxx.sh - Create a C++ compiler specific configuration
#
# Copyright (C) 1996-1999 Free Software Foundation, Inc.
# Originally by Gordon Matzigkeit <gord@gnu.ai.mit.edu>, 1996
#
# Orignal C++ support by:
#    Alexandre Oliva <oliva@lsd.ic.unicamp.br>
#    Ossama Othman <ossama@debian.org>
#    Thomas Thanner <tanner@gmx.de>
#
# This file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
# As a special exception to the GNU General Public License, if you
# distribute this file as part of a program that contains a
# configuration script generated by Autoconf, you may include it under
# the same distribution terms that you use for the rest of that program.


# Source file extension for C++ test sources.
ac_ext=C

# Object file extension for compiled C++ test sources.
objext=o

# Code to be used in simple compile tests
lt_simple_compile_test_code="int some_variable = 0;"

# Code to be used in simple link tests
lt_simple_link_test_code='int main(int, char *[]) { return (0); }'

# C++ compiler
# Allow CXX to be a program name with arguments.
set dummy $CXX
compiler=$2
CXX=${CXX-c++}

# ltmain only uses $CC for tagged configurations so make sure $CC is set.
set dummy $CC
CC=${CC-"$CXX"}
CFLAGS=${CFLAGS-"$CXXFLAGS"}

# Check if we are using GNU gcc  (taken/adapted from configure script)
# We need to check here since "--with-gcc" is set at configure time,
# not ltconfig time!
cat > conftest.$ac_ext <<EOF
#ifdef __GNUC__
  yes;
#endif
EOF
if { ac_try='${CC-c++} -E conftest.$ac_ext'; { (eval echo \"$ac_try\") 1>&5; (eval $ac_try) 2>&5; }; } | egrep yes >/dev/null 2>&1; then
  with_gcc=yes
else
  with_gcc=no
fi

# In general, the C++ compiler should always link C++ objects.
case $target in
*aix3* | *aix4*)
  # AIX just has to be different, doesn't it? :-\
  LD=makeC++SharedLib_r
  LDFLAGS="$LDFLAGS -p 0"
  ;;
*)
  LD="$CC"
  LDFLAGS="$LDFLAGS"
  ;;
esac


# PORTME: fill in a description of your system's C++ link characteristics
case "$host_os" in
  aix3*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  aix4*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  chorus*)
    case "$CXX" in
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac 
    ;;
  dgux*)
    case "$CXX" in
      ec++)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      ghcx)
        # Green Hills C++ Compiler
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  freebsd*)
    # FreeBSD uses GNU C++ and GNU ld
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  hpux*)
    case "$CXX" in
      CC)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      aCC)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  irix5* | irix6*)
    case "$CXX" in
      CC)
        # SGI C++
        archive_cmds='$CC -shared -all -multigot $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
        ;;
      *)
        if test "$with_gcc" = yes; then
          archive_cmds='$CC -shared $libobjs $deplibs $linker_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` -update_registry ${objdir}/so_locations -o $lib'
        else
          archive_cmds='$LD -shared $libobjs $deplibs $linkopts -soname $soname `test -n "$verstring" && echo -set_version $verstring` -o $lib'
        fi
        hardcode_libdir_flag_spec='${wl}-rpath ${wl}$libdir'
        hardcode_libdir_separator=:
        link_all_deplibs=yes
        ;;
    esac
    ;;
  linux*)
    case "$CXX" in
      KCC)
        # KAI C++ Compiler
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      cxx)
        # Compaq C++
        archive_cmds='$CC -shared $libobjs $deplibs $linker_flags ${wl}-soname $wl$soname -o $lib'
        archive_expsym_cmds='$CC -shared $libobjs $deplibs $linker_flags ${wl}-retain-symbols-file $wl$export_symbols'

        runpath_var=LD_RUN_PATH
        hardcode_libdir_flag_spec='-rpath $libdir'
        hardcode_libdir_separator=:

        # Commands to make compiler produce verbose output that lists
        # what "hidden" libraries, object files and flags are used when
        # linking.
        #
        # There doesn't appear to be a way to prevent this compiler from
        # explicitly linking system object files so we need to strip them
        # from the output so that they don't get included in the library
        # dependencies.
        output_verbose_link_cmds='templist=`$CC $CFLAGS -v conftest.$objext 2>&1 | grep "ld"`; templist=`echo $templist | sed "s/\(^.*ld.*\)\( .*ld .*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
          ;;
      *)
        # GNU C++ compiler
        if test "$with_gcc" = yes; then
          archive_cmds='$CC -shared -nostdlib $predeps $libobjs $deplibs $postdeps $compiler_flags ${wl}-soname $wl$soname -o $lib'
          archive_expsym_cmds='$CC -shared -nostdlib $predeps $libobjs $deplibs $postdeps $compiler_flags ${wl}-retain-symbols-file $wl$export_symbols -o $lib'

          runpath_var=LD_RUN_PATH
          hardcode_libdir_flag_spec='${wl}--rpath ${wl}$libdir'
          export_dynamic_flag_spec='${wl}--export-dynamic'

          # ancient GNU ld didn't support --whole-archive et. al.
          if eval "$CC -print-prog-name=ld --help 2>&1" | \
                egrep 'no-whole-archive' > /dev/null; then
            whole_archive_flag_spec="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'

          else
            whole_archive_flag_spec=
          fi

          # Commands to make compiler produce verbose output that lists
          # what "hidden" libraries, object files and flags are used when
          # linking.
          output_verbose_link_cmds='$CC $CFLAGS -v conftest.$objext 2>&1 | egrep "\-L"'
        fi
        ;;
    esac
    ;;
  lynxos*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  m88k*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  mvs*)
    case "$CXX" in
      cxx)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac   
    ;;
  netbsd*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  osf3*)
    if test "$with_gcc" = yes; then
      allow_undefined_flag=' ${wl}-expect_unresolved ${wl}\*'
      archive_cmds='$CC -shared -nostdlib ${allow_undefined_flag} $predeps $libobjs $deplibs $postdeps $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${objdir}/so_locations -o $lib'

      hardcode_libdir_flag_spec='${wl}-rpath ${wl}$libdir'
      hardcode_libdir_separator=:

      # Commands to make compiler produce verbose output that lists
      # what "hidden" libraries, object files and flags are used when
      # linking.
      output_verbose_link_cmds='$CC $CFLAGS -v conftest.$objext 2>&1 | egrep "\-L"'
    fi

    case "$CXX" in
      KCC)
        # KAI C++ Compiler 3.3f
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      RCC)
        # Rational C++ 2.4.1
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      cxx)
        allow_undefined_flag=' ${wl}-expect_unresolved ${wl}\*'
        archive_cmds='$CC -shared${allow_undefined_flag} $predeps $libobjs $deplibs $postdeps $linker_flags ${wl}-soname $soname `test -n "$verstring" && echo ${wl}-set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
        
        hardcode_libdir_flag_spec='${wl}-rpath ${wl}$libdir'
        hardcode_libdir_separator=:

        # Commands to make compiler produce verbose output that lists
        # what "hidden" libraries, object files and flags are used when
        # linking.
        #
        # There doesn't appear to be a way to prevent this compiler from
        # explicitly linking system object files so we need to strip them
        # from the output so that they don't get included in the library
        # dependencies.
        output_verbose_link_cmds='templist=`$CC $CFLAGS -v conftest.$objext 2>&1 | grep "ld" | grep -v "ld:"`; templist=`echo $templist | sed "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  osf4* | osf5*)
    if test "$with_gcc" = yes; then
      allow_undefined_flag=' ${wl}-expect_unresolved ${wl}\*'
      archive_cmds='$CC -shared -nostdlib ${allow_undefined_flag} $predeps $libobjs $deplibs $postdeps $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${objdir}/so_locations -o $lib'

      hardcode_libdir_flag_spec='${wl}-rpath ${wl}$libdir'
      hardcode_libdir_separator=:

      # Commands to make compiler produce verbose output that lists
      # what "hidden" libraries, object files and flags are used when
      # linking.
      output_verbose_link_cmds='$CC $CFLAGS -v conftest.$objext 2>&1 | egrep "\-L"'
    fi

    case "$CXX" in
      KCC)
        # KAI C++ Compiler 3.3f
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      RCC)
        # Rational C++ 2.4.1
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      cxx)
        allow_undefined_flag=' ${wl}-expect_unresolved ${wl}\*'
        archive_cmds='$CC -shared${allow_undefined_flag} $predeps $libobjs $deplibs $postdeps $linker_flags ${wl}-msym ${wl}-soname $soname `test -n "$verstring" && echo ${wl}-set_version $verstring` -update_registry ${objdir}/so_locations -o $lib'
        
        hardcode_libdir_flag_spec='${wl}-rpath ${wl}$libdir'
        hardcode_libdir_separator=:

        # Commands to make compiler produce verbose output that lists
        # what "hidden" libraries, object files and flags are used when
        # linking.
        #
        # There doesn't appear to be a way to prevent this compiler from
        # explicitly linking system object files so we need to strip them
        # from the output so that they don't get included in the library
        # dependencies.
        output_verbose_link_cmds='templist=`$CC $CFLAGS -v conftest.$objext 2>&1 | grep "ld" | grep -v "ld:"`; templist=`echo $templist | sed "s/\(^.*ld.*\)\( .*ld.*$\)/\1/"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  psos*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  sco*)
    case "$CXX" in
      CC)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  sunos4*)
    case "$CXX" in
      CC)
        # Sun C++ 4.x
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      lcc)
        # Lucid
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac
    ;;
  solaris*)
    case "$CXX" in
      CC)
	# Sun C++ 4.2, 5.x and Centerline C++
        no_undefined_flag=' -ztext'
        archive_cmds='$CC -G${allow_undefined_flag} -nolib -h$soname -o $lib $predeps $libobjs $deplibs $postdeps $linker_flags'
        archive_expsym_cmds='$echo "{ global:" > $lib.exp~cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
        $CC -G${allow_undefined_flag} -nolib ${wl}-M ${wl}$lib.exp -h$soname -o $lib $predeps $libobjs $deplibs $postdeps $linker_flags~$rm $lib.exp'

        hardcode_libdir_flag_spec='-R$libdir'
        hardcode_shlibpath_var=no
        case "$host_os" in
          solaris2.[0-5] | solaris2.[0-5].*) ;;
          *)
            # The C++ compiler is used as linker so we must use $wl
            # flag to pass the commands to the underlying system
            # linker.
            # Supported since Solaris 2.6 (maybe 2.5.1?)
            whole_archive_flag_spec='${wl}-z ${wl}allextract$convenience ${wl}-z ${wl}defaultextract'
            ;;
        esac
        link_all_deplibs=yes

        # Commands to make compiler produce verbose output that lists
        # what "hidden" libraries, object files and flags are used when
        # linking.
        #
        # There doesn't appear to be a way to prevent this compiler from
        # explicitly linking system object files so we need to strip them
        # from the output so that they don't get included in the library
        # dependencies.
        output_verbose_link_cmds='templist=`$CC $CFLAGS -v conftest.$objext 2>&1 | egrep "\-R|\-L"`; list=""; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; echo $list'

        AR="$CXX"
        old_archive_cmds='$AR -xar -o $oldlib $oldobjs'
        ;;
      gcx)
        # Green Hills C++ Compiler
        archive_cmds='$CC -shared $libobjs $deplibs $linker_flags ${wl}-h $wl$soname -o $lib'

        AR="$CXX $LDFLAGS"
        old_archive_cmds='$AR -archive -o $oldlib $oldobjs'
        ;;
      *)
        # GNU C++ compiler
        if test "$with_gcc" = yes; then
          if $CXX --version | egrep -v '^2\.7' > /dev/null; then
            archive_cmds='$LD -shared -nostdlib $LDFLAGS $predeps $libobjs $deplibs $postdeps $linkopts ${wl}-h $wl$soname -o $lib'
            archive_expsym_cmds='$echo "{ global:" > $lib.exp~cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
		$LD -shared -nostdlib ${wl}-M $wl$lib.exp -o $lib $predeps $libobjs $deplibs $postdeps $linkopts~$rm $lib.exp'
          else
            # g++ 2.7 appears to require `-G' NOT `-shared' on this
            # platform.
            archive_cmds='$LD -G -nostdlib $LDFLAGS $predeps $libobjs $deplibs $postdeps $linkopts ${wl}-h $wl$soname -o $lib'
            archive_expsym_cmds='$echo "{ global:" > $lib.exp~cat $export_symbols | sed -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
		$LD -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predeps $libobjs $postdeps $deplibs $linkopts~$rm $lib.exp'
          fi

          hardcode_libdir_flag_spec='${wl}-R $wl$libdir'

          # Commands to make compiler produce verbose output that lists
          # what "hidden" libraries, object files and flags are used when
          # linking.
          output_verbose_link_cmds="$CC $CFLAGS -v conftest.$objext 2>&1 | egrep \"\-L\""
        fi
        ;;
    esac   
    ;;
  tandem*)
    case "$CXX" in
      NCC)
        # NonStop-UX NCC 3.20
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
      *)
        # FIXME: insert proper C++ library support
        ld_shlibs=no
        ;;
    esac   
    ;;
  unixware*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  vxworks*)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
  *)
    # FIXME: insert proper C++ library support
    ld_shlibs=no
    ;;
esac

# Figure out "hidden" C++ library dependencies from verbose
# compiler output
cat > conftest.$ac_ext <<EOF
class Foo
{
public:
  Foo (void) { a = 0; }
private:
  int a;
};

int main (int, char *[])
{
  Foo Bar;

  return 0;
}
EOF


if eval $ac_compile 2>&5; then
  # Parse the compiler output and extract the necessary
  # object, libraries and library flags.

  # Sentinel used to keep track of whether or not we are before
  # the conftest object file.
  pre_object_deps_done=no

  for p in `eval $output_verbose_link_cmds`; do
    case $p in
    *.$objext | -L* | -R* | -l*)
       # This assumes that the test object file only shows up
       # once in the compiler output.
       if test "$p" != "conftest.$objext"; then
         if test "$pre_object_deps_done" = no; then
           predeps="$predeps $p"
         else
           postdeps="$postdeps $p"
         fi
       else
         pre_object_deps_done=yes
       fi
       ;;
    *) ;; # Ignore the rest.
    esac
  done
else
  echo "ltcf-cxx.sh: error: problem compiling test program"
fi

$rm -f confest.$objext



## Compiler Characteristics: PIC flags, static flags, etc

# We don't use cached values here since only the C compiler
# characteristics should be cached.
ac_cv_prog_cc_pic=
ac_cv_prog_cc_shlib=
ac_cv_prog_cc_wl=
ac_cv_prog_cc_static=
ac_cv_prog_cc_no_builtin=
ac_cv_prog_cc_can_build_shared=$can_build_shared

# It is not enough to reset these cached values, they must be unset.
unset ac_cv_prog_cc_pic_works
unset ac_cv_prog_cc_static_works

if test "$with_gcc" = yes; then
  ac_cv_prog_cc_wl='-Wl,'
  ac_cv_prog_cc_static='-static'

  case "$host_os" in
  beos* | irix5* | irix6* | osf3* | osf4* | osf5*)
    # PIC is the default for these OSes.
    ;;
  aix*)
    # Below there is a dirty hack to force normal static linking with -ldl
    # The problem is because libdl dynamically linked with both libc and
    # libC (AIX C++ library), which obviously doesn't included in libraries
    # list by gcc. This cause undefined symbols with -static flags.
    # This hack allows C programs to be linked with "-static -ldl", but
    # we not sure about C++ programs.
    ac_cv_prog_cc_static="$ac_cv_prog_cc_static ${ac_cv_prog_cc_wl}-lC"
    ;;
  cygwin* | mingw* | os2*)
    # This hack is so that the source file can tell whether it is being
    # built for inclusion in a dll (and should export symbols for example).
    ac_cv_prog_cc_pic='-DDLL_EXPORT'
    ;;
  amigaos*)
    # FIXME: we need at least 68020 code to build shared libraries, but
    # adding the `-m68020' flag to GCC prevents building anything better,
    # like `-m68040'.
    ac_cv_prog_cc_pic='-m68020 -resident32 -malways-restore-a4'
    ;;
  sysv4*MP*)
    if test -d /usr/nec; then
      ac_cv_prog_cc_pic=-Kconform_pic
    fi
    ;;
  *)
    ac_cv_prog_cc_pic='-fPIC'
    ;;
  esac
else
  case "$host_os" in
    aix4*)
      # All AIX code is PIC.
      ;;
    chorus*)
      case "$CXX" in
      cxch68)
        # Green Hills C++ Compiler
        # ac_cv_prog_cc_static="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
        ;;
      esac 
      ;;
    dgux*)
      case "$CXX" in
        ec++)
          ac_cv_prog_cc_pic='-KPIC'
          ;;
        ghcx)
          # Green Hills C++ Compiler
          ac_cv_prog_cc_pic='-pic'
          ;;
        *)
          ;;
      esac
      ;;
    freebsd*)
      # FreeBSD uses GNU C++
      ;;
    hpux9* | hpux10* | hpux11*)
      case "$CXX" in
        CC)
          ac_cv_prog_cc_wl='-Wl,'
          ac_cv_prog_cc_static="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
          ac_cv_prog_cc_pic='+Z'
          ;;
        aCC)
          ac_cv_prog_cc_wl='-Wl,'
          ac_cv_prog_cc_static="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
          ac_cv_prog_cc_pic='+Z'
          ;;
        *)
          ;;
      esac
      ;;
    irix5* | irix6*)
      case "$CXX" in
        CC)
          ac_cv_prog_cc_wl='-Wl,'
          ac_cv_prog_cc_static='-non_shared'
          ac_cv_prog_cc_pic='-KPIC'
          ;;
        *)
          ;;
      esac
      ;;
    linux*)
      case "$CXX" in
        KCC)
          # KAI C++ Compiler
          ac_cv_prog_cc_pic='-fPIC'
          ;;
        cxx)
          # Compaq C++
          # Make sure the PIC flag is empty.  It appears that all Alpha
          # Linux and Compaq Tru64 Unix objects are PIC.
          ac_cv_prog_cc_pic=
          ac_cv_prog_cc_static='-non_shared'
          ;;
        *)
          ;;
      esac
      ;;
    lynxos*)
      ;;
    m88k*)
      ;;
    mvs*)
      case "$CXX" in
        cxx)
          ac_cv_prog_cc_pic='-W c,exportall'
          ;;
        *)
          ;;
      esac   
      ;;
    netbsd*)
      ;;
    osf3* | osf4* | osf5*)
      case "$CXX" in
        KCC)
          # KAI C++ Compiler 3.3f
          ;;
        RCC)
          # Rational C++ 2.4.1
          ac_cv_prog_cc_pic='-pic'
          ;;
        cxx)
          # Digital/Compaq C++
          ac_cv_prog_cc_wl='-Wl,'
          # Make sure the PIC flag is empty.  It appears that all Alpha
          # Linux and Compaq Tru64 Unix objects are PIC.
          ac_cv_prog_cc_pic=
          ac_cv_prog_cc_static='-non_shared'
          ;;
        *)
          ;;
      esac
      ;;
    psos*)
      ;;
    sco*)
      case "$CXX" in
        CC)
          ac_cv_prog_cc_pic='-fPIC'
          ;;
        *)
          ;;
      esac
      ;;
    solaris*)
      case "$CXX" in
        CC)
          # Sun C++ 4.2, 5.x and Centerline C++
          ac_cv_prog_cc_pic='-KPIC'
          ac_cv_prog_cc_static='-Bstatic'
          ac_cv_prog_cc_wl='-Qoption ld '
          ;;
        gcx)
          # Green Hills C++ Compiler
          ac_cv_prog_cc_pic='-PIC'
          ;;
        *)
          ;;
      esac   
      ;;
    sunos4*)
      case "$CXX" in
        CC)
          # Sun C++ 4.x
          ac_cv_prog_cc_pic='-pic'
          ac_cv_prog_cc_static='-Bstatic'
          ;;
        lcc)
          # Lucid
          ac_cv_prog_cc_pic='-pic'
          ;;
        *)
          ;;
      esac
      ;;
    tandem*)
      case "$CXX" in
        NCC)
          # NonStop-UX NCC 3.20
          ac_cv_prog_cc_pic='-KPIC'
          ;;
        *)
          ;;
      esac   
      ;;
    unixware*)
      ;;
    vxworks*)
      ;;
    *)
      ac_cv_prog_cc_can_build_shared=no
      ;;
  esac
fi
