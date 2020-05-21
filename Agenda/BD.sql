CREATE DATABASE agenda;
USE agenda;

CREATE TABLE persona(
	idPersona integer NOT NULL AUTO_INCREMENT,
    nombre varchar(20) NOT NULL,
    apellido varchar(20) NOT NULL,
	fecnac date NOT NULL,
    
    CONSTRAINT persona_pk PRIMARY KEY(idPersona)
);

CREATE TABLE categoriatel(
	id integer NOT NULL auto_increment,
    nombre varchar(45) NOT NULL,

    CONSTRAINT cattelefono_pk PRIMARY KEY(id)
);

CREATE TABLE categoriaco(
	id integer NOT NULL auto_increment,
    nombre varchar(45) NOT NULL,

    CONSTRAINT catcorreo_pk PRIMARY KEY(id)
);

CREATE TABLE telefono(
	idPersona integer NOT NULL,
    numero integer NOT NULL,
    idCategoriaTel integer NOT NULL,

    CONSTRAINT telefono_pk PRIMARY KEY(idPersona, numero),

    CONSTRAINT telefono_fk1 FOREIGN KEY (idCategoriaTel)
		REFERENCES categoriatel (id),
    
    CONSTRAINT telefono_fk2 FOREIGN KEY (idPersona)
		REFERENCES persona (idPersona)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE correo(
	idPersona integer NOT NULL,
    nombreCorreo varchar(50) NOT NULL,
    idCategoriaCo integer NOT NULL,

    CONSTRAINT correo_pk PRIMARY KEY(idPersona, nombreCorreo),

    CONSTRAINT correo_fk1 FOREIGN KEY (idPersona)
		REFERENCES categoriaco (id),
    
    CONSTRAINT correo_fk2 FOREIGN KEY (idPersona)
		REFERENCES persona (idPersona)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

INSERT INTO persona
VALUES (1,'Antonio', 'Arjona','1970-06-10');
INSERT INTO persona
VALUES (2,'Carlota', 'Cerezo','1945-05-01');
INSERT INTO persona
VALUES (3,'Laura', 'Lopez','1983-03-17');
INSERT INTO persona
VALUES (4,'Pedro', 'Perez','1975-09-30');

INSERT INTO categoriatel
VALUES (1,'Movil');
INSERT INTO categoriatel
VALUES (2,'Fijo');

INSERT INTO categoriaco
VALUES (1,'Particular');
INSERT INTO categoriaco
VALUES (2,'Trabajo');

INSERT INTO telefono
VALUES (1,611111111,2);
INSERT INTO telefono
VALUES (1,931111111,1);
INSERT INTO telefono
VALUES (3,913333333,2);
INSERT INTO telefono
VALUES (4,913333333,2);
INSERT INTO telefono
VALUES (4,644444444,1);

INSERT INTO correo
VALUES (1,'a@hotmail.com',1);
INSERT INTO correo
VALUES (1,'a@gmail.com',2);
INSERT INTO correo
VALUES (2,'c@hotmail.com',1);
INSERT INTO correo
VALUES (3,'l@gmail.com',2);