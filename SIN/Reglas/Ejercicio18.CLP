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
)

(deffacts caracteristicas
	(caracteristica-deseada sombra)
	(caracteristica-deseada sequedad)
)

(defrule plantar
	;Dime una planta para la cual, para todas las caracteristicas de esa planta tenga las caracteristicas-deseadas
	(planta (nombre ?nombre))
	(forall
		(caracteristica-deseada ?x)
		(planta (nombre ?nombre)(caracteristicas $? ?x $?))
	)
	;Igual que el 17 pero cambiando el orden del forall
	(forall
		(planta (nombre ?nombre)(caracteristicas $? ?x $?))
		(caracteristica-deseada ?x)		
	)
	=>
	(printout t "Puedes plantar una " ?nombre crlf)
)