TEMPLATE_VARS = {
    # home info
    "$$HOME_MIN_X$$": lambda d: float(d['POI_AREA']['HOME']['@X']) - float(d['POI_AREA']['HOME']['@RADIUS']),
    "$$HOME_MAX_X$$": lambda d: float(d['POI_AREA']['HOME']['@X']) + float(d['POI_AREA']['HOME']['@RADIUS']),
    "$$HOME_MIN_Y$$": lambda d: float(d['POI_AREA']['HOME']['@Y']) - float(d['POI_AREA']['HOME']['@RADIUS']),
    "$$HOME_MAX_Y$$": lambda d: float(d['POI_AREA']['HOME']['@Y']) + float(d['POI_AREA']['HOME']['@RADIUS']),
    # robot info
    '$$NUMBER$$': lambda d: d['@KHEPERA_NB'],
    # argos input
    '$$DATA$$': lambda d: d['DATA'],
}
