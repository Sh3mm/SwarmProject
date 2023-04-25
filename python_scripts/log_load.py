import json


def parse_logs(log_file: str):
    with open(log_file) as f:
        raw_data = f.readlines()

    filtered_data = [
        line[len("BUZZ: "):]
        for line in raw_data
        if line.startswith('BUZZ: ')
    ]

    usable_data = []
    for raw_line in filtered_data:
        if 'BUZZ: ' in raw_line:
            raw_line = raw_line.split('BUZZ: ')[1]

        line = raw_line.split('|')
        has_type = len(line) == 4

        try:
            data = {
                'step': line[0],
                'id': line[1],
                'type': line[2] if has_type else ''
            }
            data.update(json.loads(line[3 if has_type else 2]))
            usable_data.append(data)
        except (json.JSONDecodeError, IndexError):
            pass

    return usable_data


def save_logs(json_file: str, data: list):
    with open(json_file, 'w') as f:
        json.dump(data, f, indent=4)
