(deffacts ejercicio19 (vector v1 1 3 4 5)(vector v2 3 4 2))

(defrule vectorOrdenado
	(forall
		(vector ?nombre $? ?x ?y $?)
		(test (<= ?x ?y))
	)	
=>
	(printout t "El vector esta ordenado: " ?nombre crlf)
)