and :: [Bool] -> Bool
and []     = True
and (x:xs) = x && and xs

concat :: [[a]] -> [a]
concat [[]]   = []
concat (xs:xss) = xs ++ concat xss

replicate :: Int -> a -> [a]
replicate 0 _ = []
replicate n a = a : replicate (n-1) a

(!!) :: [a] -> Int -> a
(!!) (x:_) 0  = x
(!!) (_:xs) n = xs !! (n-1)

insert :: Int -> [Int] -> [Int]
insert x []     = [x]
insert x (y:ys) = if x <= y then
                    x : y : ys
                  else
                    y : insert x ys

iSort :: [Int] -> [Int]
iSort []     = []
iSort (x:xs) = insert x (iSort xs)

elem :: Eq a => a -> [a] -> Bool
elem a []     = False
elem a (x:xs) | a == x = True
              | a /= x = elem a xs

halve :: [a] -> ([a], [a])
halve xs = ((take s xs), (drop s xs))
           where
             s = (length xs) `div` 2

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) | x <= y     = x : merge xs (y:ys)
                    | otherwise  = y : merge (x:xs) ys

msort :: Ord a => [a] -> [a]
msort []  = []
msort [x] = [x]
msort xs  = merge (msort ys) (msort zs)
            where (ys,zs) = halve xs
