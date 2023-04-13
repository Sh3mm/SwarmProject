from pathlib import Path
from python_scripts.template_vars import TEMPLATE_VARS


def from_template(template: str, change: dict, *, to='launch/autogenColony.argos'):
    # Read the template
    template = Path(template).resolve(strict=True)
    with template.open('r') as f:
        raw_xml = f.read()

    # replace stand-ins
    for stand_in, r_func in TEMPLATE_VARS.items():
        raw_xml = raw_xml.replace(stand_in, r_func(change))

    # Write the ARGoS file
    to = Path(to).resolve()
    with to.open('w') as f:
        f.write(raw_xml)


def get_config(config: str) -> dict:
    # Read the config files
    config = Path(config).resolve(strict=True)
    with config.open('r') as f:
        pairs = f.readlines()

    # Return a dict of the pairs identified in the config file
    pairs = [pair.split(' ') for pair in pairs]
    return {key: val for key, val in pairs}
