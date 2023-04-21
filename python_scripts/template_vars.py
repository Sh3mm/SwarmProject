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

    '$$VIS$$': lambda d: """
      <visualization>
        <qt-opengl>
          <user_functions label="buzz_qt" />
        <camera>
          <placements>
            <placement index="0" position="0,0,45" look_at="0,0,0" up="0,1,0" lens_focal_length="110"/>
          </placements>
        </camera>
        </qt-opengl>
      </visualization>
    """
}
