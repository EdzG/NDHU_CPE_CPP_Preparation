#!/usr/bin/env bash
# Recomputes the ZeroJudge solved-count badge in README.md from the .cpp
# files actually present in the ZeroJudge-mirrored folders, and rewrites
# the badge line in place.
set -euo pipefail
cd "$(dirname "$0")/.."

zerojudge_dirs=(
  "01_star_pool"
  "03_kaohsiung_Municipal_GushanSeniorHighSchoolCompetition"
)

count=$(find "${zerojudge_dirs[@]}" -name '*.cpp' | wc -l | tr -d ' ')

sed -i -E "s#(ZeroJudge%20Solved-)[0-9]+(-)#\1${count}\2#" README.md

echo "ZeroJudge solved count: ${count}"
