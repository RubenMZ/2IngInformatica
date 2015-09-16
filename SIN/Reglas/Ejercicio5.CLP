;Ejercicio5

(deffacts hecho
	(datos hola 1 3 nuevo 1 adios)
)

(defrule borraUno
	?dir<-(datos $?ca ?x&:(numberp ?x) $?co)
	(test(= ?x 1))		
=>
	(retract ?dir)
	(assert(datos $?ca $?co))
)