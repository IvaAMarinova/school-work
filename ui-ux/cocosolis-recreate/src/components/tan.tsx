import Product from "./product";
import ProductTwoSizesCard from "./product-two-sizes";

function Tan() {
    const products = [
        {
            badge: "NEW",
            image: "https://cocosolis.com/bg/wp-content/uploads/watermelon-500x500-min.png",
            name: "WATERMELON",
            usage: "Suntan & Body Oil",
            description: "За бърз, наситен и сияйна кожа. С аромат на сочна диня.",
            rating: 5,
            reviews: 126,
            price1: "45,00 лв.",
        },
        {
            award: "https://cocosolis.com/wp-content/uploads/awards-beauty-shortlist-editors-choice.png",
            image: "https://cocosolis.com/bg/wp-content/uploads/choco-thumb-500x500-min.png",
            name: "CHOCO",
            usage: "Suntan & Body Oil",
            description: "Био масло за бърз и наситен тен. Подходящо и за ежедневна употреба. С неповторим аромат на шоколад.",
            rating: 5,
            reviews: 3504,
            price1: "45,00 лв.",
            price2: "63,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/cool-thumb-500x500-min.png",
            name: "COOL",
            usage: "After Sun Oil",
            description: "Био масло за нежна хидратация и възстановяване след слънце.",
            rating: 5,
            reviews: 530,
            price1: "45,00 лв.",
            price2: "63,00 лв."
        },
        {
            badge: "MEN",
            image: "https://cocosolis.com/bg/wp-content/uploads/uomo-thumb-500x500-min.png",
            name: "UOMO",
            usage: "Suntan & Body Oil",
            description: "Био масло за мъже. За бърз, наситен тен, хидратирана и подхранена кожа. С аромат BLACK COCONUT.",
            rating: 5,
            reviews: 289,
            price1: "43,00 лв.",
            price2: "63,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/monoi-thumb-500x500-min.png",
            name: "MONOI",
            usage: "Suntan & Body Oil",
            description: "Био масло за бърз, наситен тен. С есенциално, флорално ухание на остров Таити.",
            rating: 5,
            reviews: 107,
            price1: "48,00 лв.",
            price2: "65,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/aloha-thumb-500x500-min.png",
            name: "ALOHA",
            usage: "Suntan & Body Oil",
            description: "Био масло за наситен тен. Подходящо за ежедневна употреба. С нежен кокосов аромат.",
            rating: 5,
            reviews: 1286,
            price1: "45,00 лв.",
            price2: "63,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/mango-thumb-500x500-min.png",
            name: "MANGO",
            usage: "Suntan & Body Oil",
            description: "Био масло за тен с хидратация и сияйна кожа. С чувствен аромат на тропическо манго.",
            rating: 5,
            reviews: 565,
            price1: "45,00 лв.",
            price2: "63,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/ananas-thumb-500x500-min.png",
            name: "ANANAS",
            usage: "Suntan & Body Oil",
            description: "Био масло за тен с хидратация и сияйна кожа. С аромат на сочен ананас.",
            rating: 5,
            reviews: 305,
            price1: "45,00 лв.",
            price2: "63,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/citro-thumb-500x500-min.png",
            name: "CITRO",
            usage: "Suntan & Body Oil",
            description: "Био масло за тен с хидратация и сияйна кожа. С аромат на сочни цитруси.",
            rating: 5,
            reviews: 215,
            price1: "45,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full bg-[#FBF1EB]">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-20">ТЕН</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Натурални, био масла за супер тен и сияйна кожа
            </p>

            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 w-full max-w-5xl px-4">
                {products.map((product, index) => (
                    product.price2 ? (
                        <ProductTwoSizesCard
                            key={index}
                            badge={product.badge}
                            award={product.award}
                            image={product.image}
                            name={product.name}
                            usage={product.usage}
                            description={product.description}
                            rating={product.rating}
                            reviews={product.reviews}
                            price1={product.price1}
                            price2={product.price2}
                        />
                    ) : (
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
                            price={product.price1}
                        />
                    )
                ))}
            </div>
        </div>
    );
}

export default Tan;
