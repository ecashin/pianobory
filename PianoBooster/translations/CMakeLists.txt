SET( TRANSLATIONS_FILES
     pianobooster_ja.ts
     pianobooster_es.ts
)

QT4_ADD_TRANSLATION(QM_FILES ${TRANSLATIONS_FILES})
ADD_CUSTOM_TARGET(translations ALL DEPENDS ${QM_FILES})

IF (UNIX AND NOT APPLE)
    INSTALL( FILES ${QM_FILES}
             DESTINATION share/pianobooster/translations )
ENDIF (UNIX AND NOT APPLE)

IF (WIN32)
    INSTALL( FILES ${QM_FILES}
             DESTINATION . )
ENDIF (WIN32)
