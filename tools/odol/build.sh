#!/usr/bin/env bash
# Builds the odol tool against a pinned UKSFTA-BIS checkout.
# Odol.cs reaches into BIS.P3D internals by reflection, so move the pin only after re-running
# `odol roundtrip` on a known model.
set -euo pipefail
cd "$(dirname "$0")"
BIS_COMMIT=17570f2
if [ ! -d .deps/UKSFTA-BIS ]; then
    git clone -q https://github.com/UKSFTA/UKSFTA-BIS.git .deps/UKSFTA-BIS
fi
git -C .deps/UKSFTA-BIS -c advice.detachedHead=false checkout -q "$BIS_COMMIT"
dotnet build -c Release -v q -nologo -clp:ErrorsOnly
echo "built: $(pwd)/bin/Release/net10.0/odol.exe"
