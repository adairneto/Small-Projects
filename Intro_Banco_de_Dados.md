# Introdução a banco de dados com MySQL & PHPMyAdmin

## O que são?

- Conjunto de arquivos relacionados entre si, com registros sobre algo
- Segurança e integridade dos dados
- Tipos: Relacionais e NoSQL

## Structured Query Language (SQL)

- Linguagem declarativa padrão para acessar/alterar informações
- phpMyAdmin: aplicativo para administrar MySQL
- CRUD: create, read, update, delete
- DML (Data Manipulation Language): insert, update, delete
- DDL (Data Definition Language): create table, alter table, drop table
- DQL (Data Query Language): select
- Outras cláusulas: where, group by, order by
- Operadores lógicos: and, or, not
- Operadores relacionais: <, >, <=, >=, =, <>

## Transações

Propriedades que regem a integridade de uma transação:
1. Atomicidade: "Todas as ações devem ser concluídas com sucesso, ou o processo falha como um todo e toda a ação é desfeita (rollback). Se há sucesso em todas as ações a informação é mantida no banco (commit)"
2. Consistência: "Deve-se obedecer regras e restrições definidas em um banco, como por exemplo uso de chaves estrangeiras ou uso de campos únicos"
3. Isolamento: "Cada transação deve ser independente de outras transações"
4. Durabilidade: "Os resultados de uma transação devem ser permanentes, exceto se outra transação a desfizer"

## Tipos de dados

Cada campo tem um tipo de dados:
- Char
- Varchar (string)
- Int
- Float. / double
- Date
- Not null (não pode ser vazio)
- auto_increment
- primary key
- foreign key
- text

## Criando 

``` sql
CREATE DATABASE BASETESTE;

CREATE TABLE ALUNO(
	NOME VARCHAR(255),
	EMAIL VARCHAR(255),
	DATA_NASCIMENTO DATE,
	ID SERIAL PRIMARY KEY NOT NULL
);

CREATE TABLE CURSO(
	NOME VARCHAR(255),
	DURACAO VARCHAR(20),
	ID SERIAL PRIMARY KEY
);

CREATE TABLE ALUNO_CURSO(
	ID SERIAL NOT NULL PRIMARY KEY,
	ID_ALUNO INT NOT NULL,
	ID_CURSO INT NOT NULL
);
```

Note que usamos `serial` em vez de auto_increment em PostgreSQL.

## Renomear 

``` sql
ALTER TABLE ALUNO
RENAME TO ALUNOS;
```

## Apagando tabelas

- Drop: excluir tabelas e bases de dados
- Delete: deletar dados em tabelas

``` sql
CREATE TABLE TESTEDELETE(ID INT);
DROP TABLE TESTEDELETE;
```

## Comando de inserção

``` sql
INSERT INTO ALUNOS(nome, email, data_nascimento)
VALUES('Adair', 'testeemail@emailteste.com', '2021-12-20')
RETURNING *;

INSERT INTO CURSO(nome, duracao)
VALUES('Álgebra Linear', '60 horas')
RETURNING *;

INSERT INTO CURSO(nome, duracao)
VALUES('Cálculo 1', '80 horas')
RETURNING *;

INSERT INTO ALUNO_CURSO(id_curso, id_aluno) VALUES (1,1)
```

## Deletando dados

``` sql
INSERT INTO ALUNOS(nome, email, data_nascimento)
VALUES('AdairASNeto', 'testeemail@emailteste.com', '2021-12-20')
RETURNING *;
DELETE FROM ALUNOS WHERE ID = 2
```

## Comando de seleção (buscas)

``` sql
SELECT * FROM ALUNOS;
SELECT NOME FROM ALUNOS;
SELECT * FROM ALUNOS WHERE NOME = 'Adair';

INSERT INTO ALUNOS(nome, email, data_nascimento)
VALUES('José Maria Rodrigues', 'jmr@email.com', '2021-12-20');
INSERT INTO ALUNOS(nome, email, data_nascimento)
VALUES('Maria Aparecida', 'mariaap@email.com', '2021-12-20');
SELECT * FROM ALUNOS WHERE NOME LIKE '%Maria%';
```

Adicionando critérios:

``` sql
SELECT * FROM ALUNOS WHERE DATA_NASCIMENTO >= '2021-12-20' AND NOME LIKE '%Maria%'
```

## Comando de atualização 

``` sql
UPDATE ALUNOS SET NOME = 'Maria Santos' WHERE ID = 4
```

# Seleção em várias tabelas

``` sql
INSERT INTO ALUNO_CURSO(id_curso, id_aluno) VALUES (2,3);
INSERT INTO ALUNO_CURSO(id_curso, id_aluno) VALUES (2,4);

SELECT ALUNOS.NOME, CURSO.NOME
FROM ALUNOS, CURSO, ALUNO_CURSO
WHERE ALUNOS.ID = ALUNO_CURSO.ID_ALUNO
AND CURSO.ID = ALUNO_CURSO.ID_CURSO
```