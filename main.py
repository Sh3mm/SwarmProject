import python_scripts as ps
import time
from threading import Thread
from pathlib import Path
import os
import argparse


def main(args):
    if args.exp_dir is None:
        dirs = [Path(args.exp_file)]
    else:
        dirs = Path("experiments").iterdir()

    for file in dirs:
        # log setup
        log_file = f"logs/{file.stem}.log"
        Path("logs").mkdir(exist_ok=True)
        Path("data").mkdir(exist_ok=True)

        # setting up the argos file
        configs = ps.get_config(file)
        ps.from_template("launch/TEMPLATE.argos", configs, headless=args.headless)

        # executing the sim
        thread = Thread(target=lambda: os.system(f"./run.sh launch/autogenColony.argos {log_file}"))
        print('starting experiment...')
        thread.start()
        print('started')
        thread.join(timeout=60 * int(configs['STOP_CONDITIONS']['@TIME']))
        print('experiment finished')
        time.sleep(.1)


        # collecting & treating the logs
        json_file = f"data/{file.stem}.json"
        data = ps.parse_logs(log_file)
        ps.save_logs(json_file, data)


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
