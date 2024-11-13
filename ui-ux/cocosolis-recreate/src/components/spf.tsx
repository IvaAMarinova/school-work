import Product from "./product";

function SPF() {
    const products = [
        {
            badge: "INVISIBLE ZINC",
            image: "https://cocosolis.com/bg/wp-content/uploads/spf30-thumb-500x500-min.png",
            name: "SPF30",
            usage: "Natural Sunscreen Lotion",
            description: "Натурален слънцезащитен лосион. Предпазва от UVA & UVB лъчи.",
            rating: 5,
            reviews: 368,
            price: "45,00 лв."
        },
        {
            badge: "INVISIBLE ZINC",
            award: "https://cocosolis.com/wp-content/uploads/awards-beauty-shortlist-editors-choice.png",
            image: "https://cocosolis.com/bg/wp-content/uploads/spf50-thumb-500x500-min.png",
            name: "SPF50",
            usage: "Natural Sunscreen Lotion",
            description: "Натурален слънцезащитен лосион. Предпазва от UVA & UVB лъчи. Със слънчогледово масло.",
            rating: 5,
            reviews: 355,
            price: "45,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-16">SPF</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Натурални, био слънцезащитни лосиони
            </p>

            <div className="grid grid-cols-1 sm:grid-cols-2 gap-8 w-full max-w-3xl px-4">
                {products.map((product, index) => (
                    <Product
                        key={index}
                        badge={product.badge}
                        award={product.award}
                        image={product.image}
                        name={product.name}
                        usage={product.usage}
                        description={product.description}
                        rating={product.rating}
                        reviews={product.reviews}
                        price={product.price}
                    />
                ))}
            </div>
        </div>
    );
}

export default SPF;
