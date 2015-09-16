;Ejercicio17
(deftemplate planta
	(slot nombre)
	(multislot caracteristicas)
)

(deffacts plantas
	(planta (nombre hortensia)
		(caracteristicas sombra ciudad maceta creceRapido)
	)
	(planta (nombre adelfa)
		(caracteristicas ciudad maceta cuidadoFacil creceRapido)
	)
	(planta (nombre laurel)
		(caracteristicas frio sombra sequedad sueloHumedo ciudad cuidadoFacil creceRapido)
	)
	(planta (nombre madreselva)
		(caracteristicas ciudad maceta cuidadoFacil creceRapido)
	)
	(planta (nombre gardenia)
		(caracteristicas sombra sueloAcido maceta)
	)
	(planta (nombre enebro)
		(caracteristicas frio sequedad sueloAcido ciudad cuidadoFacil)
	)
	(planta (nombre pimentero)
		(caracteristicas frio sombra sueloHumedo sueloAcido cuidadoFacil)
	)
	(planta (nombre escaramujo)
		(caracteristicas frio sombra sueloHumedo ciudad cuidadoFacil)
	)
	(planta (nombre aucuba)
		(caracteristicas sombra sequedad maceta cuidadoFacil)
	)
	(planta (nombre azalea)
		(caracteristicas sombra sueloHumedo sueloAcido maceta)
	)
)
	

(deffacts caracteristicas
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
)

(defrule plantar
	;Dime una planta para la cual, para todas las caracteristicas deseadas esa planta tenga las caracteristicas
	(planta (nombre ?nombre))
	(forall
		(caracteristica-deseada ?x)
		(planta (nombre ?nombre)(caracteristicas $? ?x $?))
	)
	=>
	(printout t "Puedes plantar una " ?nombre crlf)
)