def parse_logs(log_file):
    with open(log_file) as f:
        raw_data = f.readlines()

    filtered_data = [
        line[len("BUZZ: "):]
        for line in raw_data
        if not line.startswith('BUZZ: ')
    ]

    # TODO: treat the log according to standard
