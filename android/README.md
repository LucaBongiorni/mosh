Mosh for Android
================

is a work in progress.  Currently we can build `mosh-client` as a native-code
ARM Android executable.  There is no integration with the world of Android
applications.

The script `android/build` runs on x86 GNU/Linux and builds the executable
`src/frontend/mosh-client`.  The script expects to find the following in
`android/inputs/`:

  * `ndk`: the [Android NDK][] directory (or a symlink to same)
  * `ncurses-5.9.tar.gz`
  * `protobuf-2.4.1.tar.bz2`

[Android NDK]:  http://developer.android.com/sdk/ndk/index.html

The script `android/download` will fetch whichever of these are missing.  It
does verify checksums against some files I had lying around, but don't take
this as ultimate trust!

You will need a fairly recent NDK.  (How recent?  Let's find out someday.)


Build options
-------------

You can do a parallel build like so:

    $ MAKE_FLAGS=-j12 android/build

To skip one or another stage of compilation, you'll have to edit the last few
lines of the script.  Sorry.
