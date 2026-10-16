#!/usr/bin/env bash
# Optional: POST the progress report to bytematch.dev's upload API instead of (or as well as) the CI
# artifact. Token from $BYTEMATCH_TOKEN or ~/.config/bytematch/token (never committed).
#   tools/bk/bytematch_upload.sh [report.json]   (default: build/progress/report.json, from
#                                                 tools/bk/progress_report.py)
set -Eeuo pipefail
cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.."
REPORT=${1:-build/progress/report.json}
[[ -f $REPORT ]] || python3 -I tools/bk/progress_report.py -o "$REPORT"
TOKEN=${BYTEMATCH_TOKEN:-}
[[ -n $TOKEN || ! -f ~/.config/bytematch/token ]] || TOKEN=$(<~/.config/bytematch/token)
[[ -n $TOKEN ]] || { echo "bytematch_upload: no token (\$BYTEMATCH_TOKEN or ~/.config/bytematch/token)" >&2; exit 1; }
curl --fail -X POST -H "Authorization: Bearer $TOKEN" --data-binary @"$REPORT" \
    "https://bytematch.dev/api/v1/projects/conor-sometimes/bokura-no-kazoku-decomp/reports?version=SCPS_150.88&commit=$(git rev-parse HEAD)"
