from pathlib import Path
import re

source = Path('addons/patches/hmds/MFDJet.hpp').read_text(encoding='utf-8')
match = re.search(r'class HideOnTurn\s*\{\s*condition\s*=\s*"([^"]+)"', source)
expected = '5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)'
condition = match.group(1) if match else None
ok = condition == expected
result = f'A3CMD|A6|{"PASS" if ok else "FAIL"}|MFDJet HideOnTurn condition={condition!r}'
print(result)
raise SystemExit(0 if ok else 1)
