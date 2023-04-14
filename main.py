import python_scripts as ps
from pathlib import Path
import os


def main():
    for file in Path("experiments").iterdir():
        configs = ps.get_config(file)
        ps.from_template("launch/TEMPLATE.argos", configs)
        os.system("./run.sh launch/autogenColony.argos")


if __name__ == '__main__':
    main()
