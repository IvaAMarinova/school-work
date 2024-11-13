import Product from "./product";

function Face() {
    const products = [
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/aqua-500x500-min.png",
            name: "AQUA",
            usage: "Filler-Effect Hyaluron Supreme",
            description: "Серум за лице за ултра хидратация с 8 вида хиалуронова киселина",
            rating: 5,
            reviews: 76,
            price: "78,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/berry-500x500-min.png",
            name: "BERRY",
            usage: "Superberry Recharge Face Elixir",
            description: "Супер подхранващ и ревитализиращ еликсир за лице",
            rating: 5,
            reviews: 56,
            price: "72,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/rose-oil-500x500-min.png",
            name: "ROSE",
            usage: "Purify & Nourish Oil Cleanser",
            description: "Почистващо масло за лице с Роза Дамасцена",
            rating: 5,
            reviews: 27,
            price: "52,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/rose-foam-thumb-500x500-min.png",
            name: "ROSE",
            usage: "Clean & Hydrate Face",
            description: "Почистваща пяна за лице с Роза Дамасцена и хиалуронова киселина",
            rating: 5,
            reviews: 97,
            price: "38,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/rose-toner-thumb-500x500-min.png",
            name: "ROSE",
            usage: "Soothing Spray Toner",
            description: "Успокояващ тонер за лице с Вода от Роза Дамасцена, кактус и кокос",
            rating: 5,
            reviews: 37,
            price: "38,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-20">ЛИЦЕ</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Високоефективни натурални продукти за подмладена и сияйна кожа
            </p>
            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 w-full max-w-5xl px-4">
                {products.map((product, index) => (
                    <Product
                        key={index}
                        image={product.image}
                        name={product.name}
                        usage={product.usage}
                        description={product.description}
                        rating={product.rating}
                        reviews={product.reviews}
                        price={product.price}
                    />
                ))}
                <img
                    src="https://cocosolis.com/wp-content/uploads/face-session-break.jpg"
                    alt="Scrub"
                    className="w-full object-contain"
                />
            </div>
        </div>
    );
}

export default Face;
