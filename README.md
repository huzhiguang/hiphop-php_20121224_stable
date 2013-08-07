We develop hiphop stable(version 1.0 20121224),this version have extension:
Ice,mssql,mongodb,xcache,but redis don't add this version.

install way as follow:

#support system:
    centos 6.2 +

#Initialize the environment:
    sudo yum install git svn cpp make autoconf automake libtool patch memcached gcc-c++ cmake wget boost-devel mysql-devel pcre-devel gd-devel libxml2-devel expat-devel libicu-devel bzip2-devel oniguruma-devel openldap-devel readline-devel libc-client-devel libcap-devel binutils-devel pam-devel elfutils-libelf-devel

#support environment:
    gcc 4.6.3+ 
    boost 1.5.0

    you can install gcc 4.6.3 and boost 1.5.0

#config gcc and boost environment:
 vi ~./bashrc
    
    \#BOOST environment
    BOOST_INCLUDE=/export/files/boost-1.50/include/
    BOOST_LIB=/export/files/boost-1.50/lib
    export BOOST_INCLUDE BOOST_LIB
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/export/files/gmp-4.3.2/lib/:/export/files/mpfr-2.4.2/lib/:/export/files/mpc-0.8.1/lib/
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/export/files/gcc-4.6.3/lib64
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BOOST_INCLUDE:$BOOST_LIB
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/export/huzhiguang/files/libmemcached-1.0.10/lib
    export PATH=$BOOST_INCLUDE:$BOOST_LIB:$PATH
    
    \#gcc environment
    export PATH=/export/files/gcc-4.6.3/bin:$PATH
    export CMAKE_PREFIX_PATH=/export/dev_hhvm/usr/
    export HPHP_HOME=/export/dev_hhvm/hiphop-php_20121224_stable
    export HPHP_LIB=$HPHP_HOME/bin
    export USE_HHVM=1

save ~./bashrc

execute : source ~./bashrc
update environment

#install hhvm:
    mkdir /export/dev_hhvm
    git clone https://github.com/huzhiguang/hiphop-php_20121224_stable.git
    cd hiphop-php_20121224_stable
    cd support_package
    tar zxvf usr.tar.gz
    mv usr /export/dev_hhvm
    cd /export/dev_hhvm/hiphop-php_20121224_stable
    mkdir build
    cmake ..
    make -j 8

test $HPHP_HOME/build/src/hhvm/hhvm 

#edit extension so and include path:
PATH must /export/dev_hhvm,beacause extension link in CMake/HPHPFindLibs.cmake:

    #mongodb
	include_directories(/export/dev_hhvm/usr/include)
	target_link_libraries(${target} /export/dev_hhvm/usr/lib/mongodb_c_liulei/libmongoc.so)

	#ICE
    #include_directories(/export/huzhiguang/files/Ice-3.4.1/include)
	include_directories(/export/dev_hhvm/usr/include/freetds_wh)
	include_directories(/export/dev_hhvm/usr/include/Ice)

	target_link_libraries(${target} /export/dev_hhvm/usr/lib/Ice/libIce.so)	
	target_link_libraries(${target} /export/dev_hhvm/usr/lib/Ice/libIceUtil.so)		

	target_link_libraries(${target} /export/dev_hhvm/usr/lib/freetds_wh/libsybdb.so)
	target_link_libraries(${target} /export/dev_hhvm/usr/lib/fastlz/fastlz.o)
	
	you can edit this PATH,but edit the above path.
	
	if you want to use mssql,you should set freetds lib path.
	if your freetds path is /usr/local/freetds/ ,you can set freetds lib is :
	echo /usr/local/freetds/lib >>/etc/ld.so.conf.d/hhvm.conf
	ldconfig
	
	You can see hhvm ld,please execute:
	ldd $HPHP_HOME/build/src/hhvm/hhvm |grep libsybdb.so.5 ,you can see freetds path

=======================================================================================================================
hiphop 20121224 old readme content:
# HipHop for PHP

HipHop is a high performance PHP toolchain. Currently supported platforms are Linux and FreeBSD. There is no OS X support.

* [Developer Mailing List](http://groups.google.com/group/hiphop-php-dev)
* [Wiki](http://wiki.github.com/facebook/hiphop-php)
* [Issue Tracker](http://github.com/facebook/hiphop-php/issues)

## Required Packages

The latest information is available on the [wiki](http://wiki.github.com/facebook/hiphop-php/building-and-installing)

* cmake *2.6 is the minimum version*
* g++/gcc *4.3 is the minimum version*
* Boost *1.37 is the minimum version*
* flex
* bison
* re2c
* libmysql
* libxml2
* libmcrypt
* libicu *4.2 is the minimum version*
* openssl
* binutils
* libcap
* gd
* zlib
* tbb *Intel's Thread Building Blocks*
* [Oniguruma](http://www.geocities.jp/kosako3/oniguruma/)
* libpcre
* libexpat
* libmemcached

The following packages have had slight modifications added to them. Patches are provided and should be made against the current source copies.

* [libcurl](http://curl.haxx.se/download.html)
* src/third_party/libcurl.fb-changes.diff
* [libevent 1.4](http://www.monkey.org/~provos/libevent/)
* src/third_party/libevent-1.4.13.fb-changes.diff	OR src/third_party/libevent-1.4.14.fb-changes.diff

## Installation

You may need to point CMake to the location of your custom libcurl and libevent, or to any other libraries which needed to be installed. The *CMAKE_PREFIX_PATH* variable is used to hint to the location.

    export CMAKE_PREFIX_PATH=/home/user

To build HipHop, use the following:

Linux:

    cd /home/user/dev
    git clone git://github.com/facebook/hiphop-php.git
    cd hiphop-php
    git submodule init
    git submodule update
    export HPHP_HOME=`pwd`
    export HPHP_LIB=`pwd`/bin
    cmake .

If you are using FreeBSD instead use export - setenv

Once this is done you can generate the build file. This will return you to the shell. Finally, to build, run `make`. If any errors occur, it may be required to remove the CMakeCache.txt directory in the checkout.

    make

## Contributing to HipHop
HipHop is licensed under the PHP and Zend licenses except as otherwise noted.

Before changes can be accepted a [Contributors Licensing Agreement](http://developers.facebook.com/opensource/cla) must be signed and returned.

## Running HipHop

Please see [the wiki page](http://wiki.github.com/facebook/hiphop-php/running-hiphop)
