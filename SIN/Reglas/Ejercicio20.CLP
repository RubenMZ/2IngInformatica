;Ejercicio20

(deftemplate habitacion
	(slot id)
;	(slot ocupantes (type INTEGER)(default 0))
	(slot capacidad (type INTEGER))
;	(slot sexo(type SYMBOL)(allowed-symbols hombre mujer))
;	(slot fumador(type SYMBOL)(allowed-symbols si no))
	(multislot miembros(type SYMBOL))
)

(deftemplate persona
	(slot sexo(type SYMBOL)(allowed-symbols hombre mujer))
	(slot fumador(type SYMBOL)(allowed-symbols si no))
	(slot dni)
;	(slot asignado(type INTEGER)(default 0))
)

(deffacts hechos
	(habitacion (id 100)(capacidad 4))
	(habitacion (id 101)(capacidad 3))
	(habitacion (id 102)(capacidad 2))
	(habitacion (id 103)(capacidad 1))
	(habitacion (id 104)(capacidad 3))
	(persona (sexo hombre)(dni 11111111H)(fumador no))
	(persona (sexo hombre)(dni 22222222H)(fumador no))
	(persona (sexo hombre)(dni 33333333H)(fumador no))
	(persona (sexo hombre)(dni 44444444H)(fumador no))
	(persona (sexo mujer)(dni 55555555H)(fumador si))
	(persona (sexo mujer)(dni 66666666H)(fumador si))
	(persona (sexo mujer)(dni 77777777H)(fumador si))
	(persona (sexo hombre)(dni 88888888H)(fumador si))
	(persona (sexo mujer)(dni 99999999H)(fumador si))
	(persona (sexo hombre)(dni 10101010H)(fumador si))
	(persona (sexo mujer)(dni 12121212H)(fumador si))
	(persona (sexo hombre)(dni 13131313H)(fumador si))
	(persona (sexo hombre)(dni 14141414H)(fumador si))
)


(defrule insertaCompatible
	;Coger estudiante no asignado a ninguna habitacion
	?p<-(persona (sexo ?sex)(dni ?dni)(fumador ?fuma) )
	(not (habitacion (miembros $? ?dni $?)) )

	;Coger habitacion compatible que tenga espacio
	?h<-(habitacion (id ?idhab)
			(capacidad ?capa) 
			(miembros $?oc)
	)
	(test(< (length$ $?oc) ?capa))
	(habitacion (id ?idhab)(miembros $? ?dniOcupante $?))
	(persona (dni ?dniOcupante)(sexo ?sex)(fumador ?fuma))

	;No existe otra habitacion compatible y que sea mas grande
	(not (and
		(habitacion (id ?idhab2&~?idhab)
			(capacidad ?capa2) 
			(miembros $?oc2)
		)
		(test(< (length$ $?oc2) ?capa2))
		(habitacion (id ?idhab2)(miembros $? ?dniOcupante2 $?))
		(persona (dni ?dniOcupante2)(sexo ?sex)(fumador ?fuma))
		(test (> ?capa2 ?capa))
	))
=>
	;Hacer la asignacion del estudiante a la habitacion
	(modify ?h (miembros $?oc ?dni))
)

(defrule insertaVacia
	;Coger estudiante no asignado a ninguna habitacion
	?p<-(persona (sexo ?sex)(dni ?dni)(fumador ?fuma) )
	(not (habitacion (miembros $? ?dni $?)) )
	
	;Coger habitacion vacia
	?h<-(habitacion (id ?id)(miembros)(capacidad ?c))

	;No existe una habitacion vacia mas grande
	( not(habitacion (miembros)(capacidad ?c2&:(> ?c2 ?c)) ))

	;No existe una habitacion compatible
	(not(and
		(habitacion (id ?idhab)
				(capacidad ?capa) 
				(miembros $?oc)
		)
		(test(< (length$ $?oc) ?capa))
		(habitacion (id ?idhab)(miembros $? ?dniOcupante $?))
		(persona (dni ?dniOcupante)(sexo ?sex)(fumador ?fuma))
	))
=>
	;Asignar el estudiante a esa habitacion
	(modify ?h (miembros ?dni))
)

(defrule todasOcupadas
	;Coger estudiante no asignado a ninguna habitacion
	?p<-(persona (sexo ?sex)(dni ?dni)(fumador ?fuma) )
	(not (habitacion (miembros $? ?dni $?)) )
	
	;No existe habitacion vacia
	(not (habitacion(miembros)))

	;No existe habitacion compatible que tenga espacio
	(not(and
		(habitacion (id ?idhab)
				(capacidad ?capa) 
				(miembros $?oc)
		)
		(test(< (length$ $?oc) ?capa))
		(habitacion (id ?idhab)(miembros $? ?dniOcupante $?))
		(persona (dni ?dniOcupante)(sexo ?sex)(fumador ?fuma))
	))
=>
	(printout t "No hay espacio disponible para " ?dni crlf)
)