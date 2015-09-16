;Ejercicio23

(deftemplate producto
	(slot nombre)
	(slot precio)
)

(deftemplate compra
	(slot id)
	(slot producto)
	(slot unidades)
	(slot comprado(type INTEGER)(default 0))
)

(deftemplate factura
	(slot id)
	(slot precio)
)

(deffacts compras
	(producto (nombre huevos)(precio 3))
	(producto (nombre pan)(precio 2))
	(producto (nombre lechuga)(precio 1))
	(producto (nombre carne)(precio 5))
	(producto (nombre pescado) (precio 4))
	(compra (id 1)(producto huevos)(unidades 3))
	(compra (id 1)(producto pan)(unidades 2))
	(compra (id 1)(producto carne)(unidades 4))
	;6+4+15=25
	(compra (id 2)(producto lechuga)(unidades 7))
	;5
	(compra (id 3)(producto aceite)(unidades 4))
	(compra (id 3)(producto pescado)(unidades 1))
	;4
	(compra (id 4)(producto huevos)(unidades 10))
	;21
)	

(defrule primeraCompra
	?pro<-(compra (id ?id)(producto ?x)(unidades ?u)(comprado ?y&:(= ?y 0)))
	(producto (nombre ?x)(precio ?p))
	(not(factura(id ?id)))
=>
	(modify ?pro (comprado 1))
	( assert(factura(id ?id)(precio (*(+ (*(div ?u 3) 2)(mod ?u 3) ) ?p) )) )	
)

(defrule noPrimeraCompra
	?pro<-(compra (id ?id)(producto ?x)(unidades ?u)(comprado ?y&:(= ?y 0)))
	(producto (nombre ?x)(precio ?p))
	?f<-(factura(id ?id)(precio ?p2))
=>
	(modify ?pro (comprado 1))
	( modify ?f	(precio (+ 
				(*(+ (*(div ?u 3)2)(mod ?u 3) )?p) ?p2)
			)
	)
)

(defrule noHayProducto
	(compra (id ?id)(producto ?x)(unidades ?u))
	(not(producto (nombre ?x)(precio ?p)))
=>
	(printout t "No existe producto " ?x crlf)
)