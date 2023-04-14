from pathlib import Path
from typing import Union
import xmltodict
from python_scripts import TEMPLATE_VARS


def from_template(template: str, change: dict, *, to='launch/autogenColony.argos'):
    # Read the template
    template = Path(template).resolve(strict=True)
    with template.open('r') as f:
        raw_xml = f.read()

    # replace stand-ins
    for stand_in, r_func in TEMPLATE_VARS.items():
        raw_xml = raw_xml.replace(stand_in, str(r_func(change)))

    # Write the ARGoS file
    to = Path(to).resolve()
    with to.open('w') as f:
        f.write(raw_xml)


def get_config(config: Union[Path, str]) -> dict:
    # Read the config files
    config = Path(config).resolve(strict=True)
    with config.open('r') as f:
        raw_config = f.read()

    config_dict = xmltodict.parse(raw_config)['data']
    config_dict['DATA'] = raw_config
    return config_dict
