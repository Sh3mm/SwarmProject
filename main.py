import python_scripts as ps
from pathlib import Path
import os
import argparse


def main(args):
    if args.exp_dir is None:
        dirs = [Path(args.exp_file)]
    else:
        dirs = Path("experiments").iterdir()

    for file in dirs:
        configs = ps.get_config(file)
        ps.from_template("launch/TEMPLATE.argos", configs, headless=args.headless)
        os.system("./run.sh launch/autogenColony.argos")


if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    group = parser.add_mutually_exclusive_group()
    group.add_argument(
        "-f", "--exp-file", default="experiments/Exemple.xml", help="Path to the experiment variables file"
    )
    group.add_argument(
        "-d", "--exp-dir", help="Path to the experiment variables directory"
    )

    parser.add_argument("--headless", action='store_true', help="run the experiment without UI")
    main(parser.parse_args())
