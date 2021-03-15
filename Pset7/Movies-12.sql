SELECT title FROM
(SELECT title FROM movies INNER JOIN stars ON movies.id = stars.movie_id, people ON stars.person_id = people.id WHERE people.name = "Johnny Depp" OR
people.name = "Helena Bonham Carter") GROUP BY title HAVING COUNT(title) > 1
