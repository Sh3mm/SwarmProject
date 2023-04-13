TEMPLATE_VARS = {
    # home info
    '$$HOME_Y$$': lambda d: d['homeY'],
    '$$HOME_X$$': lambda d: d['homeX'],
    '$$HOME_RADIUS$$': lambda d: d['homeR'],
    "$$HOME_MIN_X$$": lambda d: d['homeX'] - d['homeX'],
    "$$HOME_MAX_X$$": lambda d: d['homeX'] + d['homeX'],
    "$$HOME_MIN_Y$$": lambda d: d['homeY'] - d['homeR'],
    "$$HOME_MAX_Y$$": lambda d: d['homeY'] + d['homeR'],
    # goal info
    '$$GOAL_Y$$': lambda d: d['goalY'],
    '$$GOAL_X$$': lambda d: d['goalX'],
    '$$GOAL_RADIUS$$': lambda d: d['goalR'],
    # robot info
    '$$NUMBER$$': lambda d: d['kheperaNb']
}
