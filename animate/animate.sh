#!/bin/bash

set -e -o pipefail

for f in frames/*.txt; do
  if [ ! -f "${f/txt/gif}" ]; then
    convert -size 425x190 xc:white \
      -font "FreeMono-Bold" -pointsize 15 -fill black \
      -annotate +20+25 "@$f" "${f/txt/gif}"
  fi
done

convert -delay 100 -loop 0 frames/*.gif demo.gif

exit 0
